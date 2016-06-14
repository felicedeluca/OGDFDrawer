#include <ogdf/basic/Graph.h>
#include <ogdf/basic/graph_generators.h>
#include <ogdf/layered/DfsAcyclicSubgraph.h>
#include <ogdf/fileformats/GraphIO.h>

#include <dos.h>
#include <stdio.h>
#include <conio.h>

#include <sstream>  //for std::istringstream
#include <iostream>
#include <fstream>


#pragma once
class Converter
{
public:
	Converter();
	~Converter();

	void convertGMLToDOT(string inputfile, string outputPath);
};

