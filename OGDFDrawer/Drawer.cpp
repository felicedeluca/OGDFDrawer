#include "Drawer.h"

using namespace ogdf;


string outputPath;

LARGE_INTEGER frequency;        // ticks per second
LARGE_INTEGER t1, t2;           // ticks
double elapsedTime;

BOOLEAN printTime = false;
BOOLEAN printLog = false;


void writeToFile(GraphAttributes GA, string full_path) {
	ofstream myfile;

	myfile.open(full_path);

	GraphIO::writeGML(GA, myfile);

	myfile.flush();
	myfile.close();


	cout << "\n" << full_path;


	//	GraphIO::writeGML(GA, outputName);

}

//FMMM
void drawWithFMMMLayout(GraphAttributes GA, string outputfilename) {

	string outputName = outputPath + outputfilename + "_FMMM_drawing" + ".gml";


	if (printLog) cout << "Drawing with FMMM\n";

	FMMMLayout layout;

	layout.useHighLevelOptions(true);
	layout.unitEdgeLength(15.0);
	layout.newInitialPlacement(true);
	layout.qualityVersusSpeed(FMMMLayout::qvsGorgeousAndEfficient);

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	if (printTime)
		cout << "FMMM. " << elapsedTime << "\n";

	writeToFile(GA, outputName);

}


//Tree Layout
void drawWithTreeLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing Tree.\n";


	string outputName = outputPath + outputfilename + "_Tree_drawing" + ".gml";
	TreeLayout  layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	if (printTime)
		cout << "Tree. " << elapsedTime << "\n";

	writeToFile(GA, outputName);

}

//Radial Tree Layout
void drawWithRadialTreeLayout(GraphAttributes GA, string outputfilename) {

	
	if(printLog) cout << "Drawing Radial Tree.\n";


	string outputName =outputPath+ outputfilename+ "_RadTree_drawing"+".gml";
	RadialTreeLayout  layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	if(printTime)
	cout << "RadTree. "<<elapsedTime<<"\n";

	writeToFile(GA, outputName);
	

}


//DavidsonHarel 
void drawWithDavidsonHarelLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with DH.\n";


	string outputName = outputPath + outputfilename + "_DH_drawing" + ".gml";
	DavidsonHarelLayout  layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	if (printTime)
		cout << "dh. " << elapsedTime << "\n";

	writeToFile(GA, outputName);

}

//KK 
void drawWithSpringEmbedderKKLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with KK.\n";

	string outputName = outputPath + outputfilename + "_KK_drawing" + ".gml";
	SpringEmbedderKK layout;
	layout.setUseLayout(true);

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	if (printTime)
		cout << "kk. " << elapsedTime << "\n";

	writeToFile(GA, outputName);

}

//GEM
void drawWithGEMLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with GEM.\n";

	string outputName = outputPath + outputfilename + "_GEM_drawing" + ".gml";
	GEMLayout gem;
	gem.desiredLength(65);

	QueryPerformanceCounter(&t1);
	gem.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	if (printTime)
		cout << "gem. " << elapsedTime << "\n";


	writeToFile(GA, outputName);

}

//FR
void drawWithFRLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with FR.\n";


	string outputName = outputPath + outputfilename + "_FR_drawing" + ".gml";
	SpringEmbedderFR  layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;


	if (printTime)
		cout << "fr. " << elapsedTime << "\n";

	writeToFile(GA, outputName);

}

//FR Exact
void drawWithFRExactLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with FR Exact.\n";


	string outputName = outputPath + outputfilename + "_FRExact_drawing" + ".gml";
	SpringEmbedderFRExact  layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;


	if (printTime)
		cout << "fr exact: " << elapsedTime << "\n";

	writeToFile(GA, outputName);

}

//LinLog
void drawWithFRLinLogLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with LinLog.\n";


	string outputName = outputPath + outputfilename + "_LinLog_drawing" + ".gml";
	SpringEmbedderFRLinLog  layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;


	if (printTime)
		cout << "LinLog: " << elapsedTime << "\n";

	writeToFile(GA, outputName);

}

//FMME
void drawWithFMMELayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with FMME.\n";


	string outputName = outputPath + outputfilename + "_FMME_drawing" + ".gml";
	FastMultipoleMultilevelEmbedder layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

	if (printTime)
		cout << "fmme. " << elapsedTime << "\n";


	writeToFile(GA, outputName);

}

//MMM
void drawWithMMMLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with MMM.\n";

	string outputName = outputPath + outputfilename + "_MMM_drawing" + ".gml";
	ModularMultilevelMixer layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;


	if (printTime)
		cout << "mmm. " << elapsedTime << "\n";


	writeToFile(GA, outputName);

}

//Stress Minimization
void drawWithSMLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with SM.\n";

	string outputName = outputPath + outputfilename + "_SM_drawing" + ".gml";
	StressMinimization layout;
	layout.hasInitialLayout(true);

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;


	if (printTime)
		cout << "sm. " << elapsedTime << "\n";


	writeToFile(GA, outputName);

}

//Planar
void drawWithPlanarLayout(GraphAttributes GA, string outputfilename) {

	if (printLog) cout << "Drawing with Planar Layout.\n";

	string outputName = outputPath + outputfilename + "_Planar_drawing" + ".gml";
	PlanarDrawLayout layout;

	QueryPerformanceCounter(&t1);
	layout.call(GA);
	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;


	if (printTime)
		cout << "sm. " << elapsedTime << "\n";


	writeToFile(GA, outputName);


}

void store_coordinate(string graph_name, std::map<int, int> x, std::map<int, int> y) {

	ofstream coo_files;

	coo_files.open("backup/coo_" + graph_name + ".txt");

	std::map<int, int>::iterator it;

	for (it = x.begin(); it != x.end(); it++)
	{
		int identifier = it->first;
		int x_coo = x[identifier];
		int y_coo = y[identifier];

		coo_files << identifier << ";";
		coo_files << x_coo << ";";
		coo_files << y_coo << "\n";

	}

	coo_files.flush();
	coo_files.close();

	cout << "coo stored";

}


std::map<int, int> init_x;
std::map<int, int> init_y;


bool restore_coordinate(string graph_name) {

	ifstream myReadFile;
	myReadFile.open("backup/coo_" + graph_name + ".txt");
	if (myReadFile.is_open()) {

		std::string line;
		while (std::getline(myReadFile, line))
		{
			std::vector<int> vect;
			std::stringstream ss(line);
			int i;

			while (ss >> i)
			{
				vect.push_back(i);

				if (ss.peek() == ';')
					ss.ignore();
			}

			int id = vect.at(0);
			int x = vect.at(1);
			int y = vect.at(2);

			init_x[id] = x;
			init_y[id] = y;

		}

		myReadFile.close();
		cout << "restored coordinate\n";
		return true;

	}
	else {

		cout << "coordinate file not found\n";
		myReadFile.close();

		return false;
	}


	myReadFile.close();
}



Drawer::Drawer()
{
}


Drawer::~Drawer()
{
}


void Drawer::computeDrawingForGraph(string graphFileName, string outputgraphpath, string algorithms, int repeat)
{
	unsigned found = graphFileName.find_last_of("/\\");

	string outputGraphName = graphFileName.substr(found + 1);

	outputPath = outputgraphpath;

	Graph G;
	GraphAttributes GA(G,
		GraphAttributes::nodeGraphics |
		GraphAttributes::edgeGraphics |
		GraphAttributes::nodeLabel |
		GraphAttributes::edgeStyle |
		GraphAttributes::nodeStyle |
		GraphAttributes::nodeTemplate);
	if (!GraphIO::readGML(GA, G, graphFileName)) {
		cerr << "Could not load " << graphFileName << endl;
		throw 999;
		return;
	}


	cout << "V: " << G.numberOfNodes() << " E: " << G.numberOfEdges() << "\n";



	ogdf::node v;

	outputGraphName = outputGraphName.substr(0, outputGraphName.find_last_of("."));


	string outputGraphNameTemp = outputGraphName;

	srand(time(NULL));


	for (int i = 0; i < repeat; ++i) {


		string outputGraphName = outputGraphNameTemp + "_d_" + std::to_string(i);

		bool restored = restore_coordinate(outputGraphName);

		if (!restored) {
			forall_nodes(v, G) {

				int index = v->index();
				int x = rand() % 1000;
				int y = rand() % 1000;

				init_x[index] = x;
				init_y[index] = y;
			}

			store_coordinate(outputGraphName, init_x, init_y);

		}


		if (algorithms.find("radial") != std::string::npos) {

			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}

			drawWithRadialTreeLayout(GA, outputGraphName); //RadTree

			Sleep(0.2);

		}


		if (algorithms.find("tree") != std::string::npos) {

			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}

			drawWithTreeLayout(GA, outputGraphName); //Tree

			Sleep(0.5);

		}

		if (algorithms.find("linlog") != std::string::npos) {


			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}

			drawWithFRLinLogLayout(GA, outputGraphName); //FRLinLog


			Sleep(0.2);
		}


		if (algorithms.find("fr") != std::string::npos) {

			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}

			drawWithFRExactLayout(GA, outputGraphName); //FRExact

			Sleep(0.2);


		}

		if (algorithms.find("kk") != std::string::npos) {


			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}

			drawWithSpringEmbedderKKLayout(GA, outputGraphName); //KK

			Sleep(0.2);

		}

		if (algorithms.find("gem") != std::string::npos) {


			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}

			drawWithGEMLayout(GA, outputGraphName); //GEM

			Sleep(0.2);


		}

		if (algorithms.find("fmmm") != std::string::npos) {


			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}
			drawWithFMMMLayout(GA, outputGraphName); //FMMM

			Sleep(0.2);

		}

		if (algorithms.find("planar") != std::string::npos) {

			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}

			drawWithPlanarLayout(GA, outputGraphName); //Planar

			Sleep(0.2);


		}

		if (algorithms.find("sm") != std::string::npos) {

			forall_nodes(v, G) {

				int index = v->index();
				int x = init_x[index];
				int y = init_y[index];

				GA.width(v) = GA.height(v) = 10.0;
				GA.x(v) = x;
				GA.y(v) = y;
			}

			drawWithSMLayout(GA, outputGraphName); //SM
		}

	}

}
