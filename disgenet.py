# Copyright [2010-2015] Integrative Biomedical Informatics Group, Research Programme on Biomedical Informatics (GRIB) IMIM-UPF 
# http://ibi.imim.es/
# contact for technical questions support@disgenet.org
# creator: jpinero@imim.es  

import argparse
import urllib.request, urllib.error, urllib.parse

def main(infile, outfile, entity, identifier):
    fi = open(infile, "r")
    fo = open(outfile, "w")
    ent = entity
    id = identifier

    STR = "" 
    if ent == "gene" :
         if id == "hgnc":
            STR = "c2.name = '"
         elif id == "entrez":
            STR = "c2.geneId = '"
         else: 
            print ("the type of identifier must be entrez gene identifiers or gene symbols \n")
    elif ent == "disease" :
        if id == "cui":
            STR = "c1.cui = '"
        elif id == "mesh":
            STR = "c1.MESH = '"
        elif id == "omim":
            STR = "c1.omimInt = '"
        else: 
            print ("the type of identifier must be cui or mesh or omim identifiers\n")
    else: 
        print ("the type of entity must be disease or gene \n")
 
    for line in fi:
        intfield = line.strip()	
        str = "";
        MSG = "" 
        seq1 = ("querying entity :  ", intfield, "  " )
        MSG = str.join( seq1 );
        print (MSG)       

        seq = ( """
        DEFINE
            c0='/data/gene_disease_score_onexus',
            c1='/data/diseases',
            c2='/data/genes',
            c3='/data/sources'
        ON
            'http://bitbucket.org/janis_pi/disgenet_onexus.git'
        SELECT
            c2 (geneId, name, uniprotId, description, pathName, pantherName),
            c1 (cui, name, diseaseClassName, STY, MESH, omimInt),

            c0 (score, pmids)
        FROM
            c0
        WHERE
            (
                """ + STR +  intfield+"""'
            AND
                c3 = 'ALL'
            )
        ORDER BY
            c0.score DESC""" ); #

        binary_data = seq.encode("utf-8")
        # print query
        req = urllib.request.Request("http://www.disgenet.org/oql")
        res = urllib.request.urlopen(req, binary_data)
        # print res.read() 
        data  = res.read().decode("utf-8")
        #print 'LENGTH  :', len(data)
        if len(data) == 152: 
            MSG = "" 
            seq1 = (entity, " " , intfield, " is not in DisGeNET \n " )
            MSG = str.join( seq1 );
            print (MSG)
        else:
             fo.write(data)

    fi.close()
    fo.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument("infile", metavar="input-file",help="input file")
    parser.add_argument("outfile", metavar="output-file",help="output file")
    parser.add_argument("entity", metavar="entity",help="type of entity: gene or disease")
    parser.add_argument("identifier", metavar="identifier",help="identifier type: \n genes:  hgnc or entrez \n diseases: cui, mesh or omim ")

    args = parser.parse_args()

    main(args.infile, args.outfile, args.entity, args.identifier)