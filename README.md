# SeqNoise
# Language: C++
# Input: TXT
# Output: PREFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: AmpliconNoise 1.29

PluMA plugin to cluster sequences from FASTA file (Quince et al, 2011).

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
fastafile       Sequences
distfile        Sequence distance matrix (see SeqDist)
listfile        Output list of clusters
lookupfile      DAT file for database
s      	Precision
c       Cutoff
mapfile Input mapping

The PREFIX is used for the output directory, for FASTAs.  In addition, three files will be produced:
PREFIX.fa
PREFIX.mapping
PREFIX.list
