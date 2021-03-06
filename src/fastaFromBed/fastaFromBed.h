/*****************************************************************************
  fastaFromBed.h

  (c) 2009 - Aaron Quinlan
  Hall Laboratory
  Department of Biochemistry and Molecular Genetics
  University of Virginia
  aaronquinlan@gmail.com

  Licenced under the GNU General Public License 2.0 license.
******************************************************************************/
#ifndef FASTAFROMBED_H
#define FASTAFROMBED_H

#include "bedFile.h"
#include "BlockedIntervals.h"
#include "sequenceUtils.h"
#include "Fasta.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//************************************************
// Class methods and elements
//************************************************
class Bed2Fa {

public:

    // constructor
    Bed2Fa(bool useName, const string &dbFile, 
           const string &bedFile,
           bool useFasta, bool useStrand, 
           bool useBlocks, bool useFullHeader,
           bool useBedOut);

    // destructor
    ~Bed2Fa(void);

    void ExtractDNA();
    void ReportDNA(const BED &bed, string &dna);


private:

    bool _useName;
    string _dbFile;
    string _bedFile;
    bool _useFasta;
    bool _useBedOut;    // priginal BED records followed by FASTA on same line
    bool _useStrand;    // should the extracted sequence obey strandedness?
    bool _useBlocks;    // should the extracted sequence obey BED blocks
                        // (for example, exons?)
    bool _useFullHeader;

    // instance of a bed file class.
    BedFile  *_bed;
};

#endif
