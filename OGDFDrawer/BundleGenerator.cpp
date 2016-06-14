#include "BundleGenerator.h"
#include <ogdf/basic/Graph.h>
#include <ogdf/basic/graph_generators.h>
#include <ogdf/layered/DfsAcyclicSubgraph.h>
#include <ogdf/fileformats/GraphIO.h>
#include <ogdf/layered/OptimalRanking.h>
#include <ogdf/layered/MedianHeuristic.h>
#include <ogdf/layered/OptimalHierarchyLayout.h>

#include <ogdf/energybased/FMMMLayout.h>
#include <ogdf/energybased/SpringEmbedderKK.h>
#include <ogdf/energybased/SpringEmbedderFR.h> 
#include <ogdf/energybased/SpringEmbedderFRExact.h> 
#include <ogdf/energybased/DavidsonHarelLayout.h>
#include <ogdf/energybased/FastMultipoleEmbedder.h>
#include <ogdf/energybased/StressMinimization.h>
#include <ogdf\basic\GraphAttributes.h>
#include <ogdf\energybased\GEMLayout.h>
#include <ogdf/energybased/multilevelmixer/ModularMultilevelMixer.h>
#include <ogdf/tree/RadialTreeLayout.h>
#include <ogdf/tree/TreeLayout.h>


#include <ogdf/planarlayout/PlanarDrawLayout.h>
#include <ogdf/planarlayout/PlanarStraightLayout.h>

#include <SpringEmbedderFRLinLog.h>


#include <dos.h>
#include <stdio.h>
#include <conio.h>

#include <sstream>  //for std::istringstream
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <fstream>



BundleGenerator::BundleGenerator()
{
}


BundleGenerator::~BundleGenerator()
{
}

void BundleGenerator::generatePlanarGraphs(string outputPath)
{

	int n[4] = { 50, 100, 150, 200 };

	int dmax = 20;
	int dmin = 15;

	int d_diff = dmax - dmin;

	int instances = 30;

	for (int i = 0; i < 4; ++i) {

		int nodes = n[i];

		for (int instance = 0; instance < instances; ++instance) {

			double density = (dmin + (rand() % (d_diff + 1))) / 10.0;

			Graph G;
			GraphAttributes GA(G,
				GraphAttributes::nodeGraphics |
				GraphAttributes::edgeGraphics |
				GraphAttributes::nodeLabel |
				GraphAttributes::edgeStyle |
				GraphAttributes::nodeStyle |
				GraphAttributes::nodeTemplate);

			planarConnectedGraph(G, nodes, nodes*density);

			std::stringstream stream;
			stream << std::fixed << std::setprecision(1) << density;
			string s = stream.str();

			string name = "planar_" + std::to_string(nodes) + "_" + std::to_string(density) + "_" + std::to_string(instance) + ".gml";


			GraphIO::writeGML(GA, outputPath + name);

		}

	}

}