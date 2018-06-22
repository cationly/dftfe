// ---------------------------------------------------------------------
//
// Copyright (c) 2017-2018 The Regents of the University of Michigan and DFT-FE authors.
//
// This file is part of the DFT-FE code.
//
// The DFT-FE code is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the DFT-FE distribution.
//
// ---------------------------------------------------------------------
//
// @author Shukan Parekh, Phani Motamarri
//

#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <tuple>
#include <stack>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <fstream>

#ifndef xmlTodftfeParser_h
#define xmlTodftfeParser_h

namespace dftfe{
  //
  //Declare pseudoUtils function
  //
namespace pseudoUtils
{

class xmlTodftfeParser{

private:
    xmlDoc *doc;
    xmlNode *root;
    double mesh_spacing;
    std::vector<std::string> local_potential;
    std::vector<std::string> density;
    std::vector<std::string> mesh;
    std::vector<std::tuple<size_t, size_t, std::vector<std::string>>> projectors;
    std::vector<std::tuple<size_t, size_t, size_t, double>> d_ij;
    
    std::ofstream loc_pot;
    std::ofstream dense;
    std::ofstream denom;
    std::ofstream l1;
    std::ofstream l2;
    std::ofstream l3;
    std::ofstream ad_file;
    std::ofstream pseudo;
    
public:
    /**
     * class constructor
     */
    xmlTodftfeParser();

    /**
     * class destructor
     */
    ~xmlTodftfeParser();

    /**
     * @brief parse a given xml pseudopotential file 
     * 
     * @param filePath location of the xml file
     */
    bool parseFile(std::string & filePath);

    /**
     * @brief output the parsed xml pseudopotential file into dat files required by dftfe code
     * 
     * @param filePath location to write the data
     */
    bool outputData(std::string & filePath);

};

}

}
#endif /* parser_h */
