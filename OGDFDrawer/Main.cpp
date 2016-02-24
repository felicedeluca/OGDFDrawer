 
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
#include <ogdf/energybased/DavidsonHarelLayout.h>
#include <ogdf/energybased/FastMultipoleEmbedder.h>
#include <ogdf\basic\GraphAttributes.h>
#include <ogdf\energybased\GEMLayout.h>
#include <ogdf/energybased/multilevelmixer/ModularMultilevelMixer.h>

using namespace ogdf;

string outputPath;


//FMMM
void drawWithFMMMLayout(GraphAttributes GA, string outputfilename){

	//	cout << "Drawing with FMMM.\n";


	string outputName = outputPath+"FMMM_drawing_" + outputfilename;

	FMMMLayout layout;
 
	layout.useHighLevelOptions(true);
	layout.unitEdgeLength(15.0);
	layout.newInitialPlacement(true);
	layout.qualityVersusSpeed(FMMMLayout::qvsGorgeousAndEfficient);
 
	layout.call(GA);
	GraphIO::writeGML(GA, outputName);

}


//DavidsonHarel 
void drawWithDavidsonHarelLayout(GraphAttributes GA, string outputfilename){

	//	cout << "Drawing with DH.\n";


	string outputName =outputPath+ "DH_drawing_" + outputfilename;
	DavidsonHarelLayout  layout;
	layout.call(GA);
	GraphIO::writeGML(GA, outputName);

}

//KK 
void drawWithSpringEmbedderKKLayout(GraphAttributes GA, string outputfilename){
		
	//cout << "Drawing with KK.\n";

	string outputName = outputPath+"KK_drawing_" + outputfilename;
	SpringEmbedderKK layout;
	layout.setUseLayout(true);
	layout.call(GA);
	GraphIO::writeGML(GA, outputName);

}

//GEM
void drawWithGEMLayout(GraphAttributes GA, string outputfilename){

	//cout << "Drawing with GEM.\n";

	string outputName = outputPath+"GEM_drawing_" + outputfilename;
	GEMLayout gem;
	gem.desiredLength(65);
	gem.call(GA);
	GraphIO::writeGML(GA, outputName);

}

//FR
void drawWithFRLayout(GraphAttributes GA, string outputfilename){

	//	cout << "Drawing with FR.\n";


	string outputName = outputPath+"FR_drawing_" + outputfilename;
	SpringEmbedderFR  layout;
	layout.call(GA);
	GraphIO::writeGML(GA, outputName);

}

//FMME
void drawWithFMMELayout(GraphAttributes GA, string outputfilename){

	//	cout << "Drawing with FMME.\n";


	string outputName = outputPath+"FMME_drawing_" + outputfilename;
	FastMultipoleMultilevelEmbedder layout;
	layout.call(GA);
	GraphIO::writeGML(GA, outputName);

}

//MMM
void drawWithMMMLayout(GraphAttributes GA, string outputfilename){

	//cout << "Drawing with MMM.\n";

	string outputName = outputPath+"MMM_drawing_" + outputfilename;
	ModularMultilevelMixer layout;
	layout.call(GA);
	GraphIO::writeGML(GA, outputName);

}


void computeDrawingForGraph(string graphFileName){

	string inputGraphName = "graph.gml";
	string outputGraphName =  inputGraphName;

	Graph G;
	GraphAttributes GA(G,
	  GraphAttributes::nodeGraphics |
	  GraphAttributes::edgeGraphics |
	  GraphAttributes::nodeLabel |
	  GraphAttributes::edgeStyle |
	  GraphAttributes::nodeStyle |
	  GraphAttributes::nodeTemplate);
	if (!GraphIO::readGML (GA, G, graphFileName) ) {
		cerr << "Could not load " << graphFileName << endl;
		throw 999;
		return;
	}

	
	node v;
	forall_nodes(v,G){
		GA.width(v) = GA.height(v) = 10.0;
		GA.x(v) = rand() % 1000;
		GA.y(v) = rand() % 1000;	}

	drawWithFMMMLayout(GA, outputGraphName); //FMMM
	drawWithDavidsonHarelLayout(GA, outputGraphName); //DH
	drawWithSpringEmbedderKKLayout(GA, outputGraphName); //KK
	drawWithGEMLayout(GA, outputGraphName); //GEM
	drawWithFRLayout(GA, outputGraphName); //FR
	drawWithFMMELayout(GA, outputGraphName); //FMME
	drawWithMMMLayout(GA, outputGraphName); //MMM


}


int main(int argc, char* argv[])
{

	
	if(argc != 3)
   {
	cout << "Missing parameter.\n Usage: filePath outputhPath";
      return (-1);
   }
	
	string filePath = argv[1];
	outputPath = argv[2];

	cout << "Drawing: " << filePath << "\n";

	cout << "Saving in " << outputPath << "\n";

	 try
  {
	computeDrawingForGraph(filePath); 
	 
	}
  catch (int e)
  {
	  //here you can handle readeing issues for the current graph
  }

	cout << "END.\n";
	cout << "press a button to close.\n";

	string end;
	cin >> end;

    return 0; 


}
//end of the main