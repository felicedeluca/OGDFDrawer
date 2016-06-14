
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
#include <iostream>
#include <fstream>

#pragma once
class Drawer
{
public:
	Drawer();
	~Drawer();

	void computeDrawingForGraph(string graphFileName, string outputgraphpath, string algorithms, int repeat);
};

