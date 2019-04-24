#include "Converter.h"


using namespace ogdf;

Converter::Converter()
{
}


Converter::~Converter()
{
}

void Converter::convertGMLToDOT(string inputfile, string outputPath)
{
	unsigned found = inputfile.find_last_of("/\\");

	string outputGraphName = inputfile.substr(found + 1);


	Graph G;
	GraphAttributes GA(G,
		GraphAttributes::nodeGraphics |
		GraphAttributes::edgeGraphics |
		GraphAttributes::nodeLabel |
		GraphAttributes::edgeStyle |
		GraphAttributes::nodeStyle |
		GraphAttributes::nodeTemplate);
	if (!GraphIO::readGML(GA, G, inputfile)) {
		cerr << "Could not load " << inputfile << endl;
		throw 999;
		return;
	}


	outputGraphName = outputGraphName.substr(0, outputGraphName.find_last_of("."));
	string outputName = outputPath + outputGraphName + ".dot";


	ofstream myfile;

	myfile.open(outputName);

	GraphIO::writeDOT(GA, myfile);

	myfile.flush();
	myfile.close();
}
