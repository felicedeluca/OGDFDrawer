#include <dos.h>
#include <stdio.h>
#include <conio.h>

#include <sstream>  //for std::istringstream
#include <iostream>
#include <fstream>

#include <Drawer.h>
#include <BundleGenerator.h>
#include <Converter.h>


char* getCmdOption(char ** begin, char ** end, const std::string & option)
{
	char ** itr = std::find(begin, end, option);
	if (itr != end && ++itr != end)
	{
		return *itr;
	}
	return 0;
}


bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
	return std::find(begin, end, option) != end;
}



int main(int argc, char* argv[])
{

	if (cmdOptionExists(argv, argv + argc, "-h"))
	{
		// Do stuff
	}

	char * draw = getCmdOption(argv, argv + argc, "-DRAW");
	
	if (draw) {

		char * input = getCmdOption(argv, argv + argc, "-i");
		char * output = getCmdOption(argv, argv + argc, "-o");

		string algorithms_string = string(draw);

		char * repeat_cmd = getCmdOption(argv, argv + argc, "-c");
		string repeat_str = string(repeat_cmd);
		int repeat = std::stoi(repeat_str);

		if (input && output && repeat > 0)
		{
			string input_string = string(input);
			string output_string = string(output);

			try
			{
				Drawer drawer;
				drawer.computeDrawingForGraph(input_string, output_string, algorithms_string, repeat);

			}
			catch (int e)
			{
			}

		}
		else {
			cout << "missing input and output (-i -o)";
			return (-1);
		}

		return (0);
	}



	char * generate = getCmdOption(argv, argv + argc, "-GEN");

	if (generate) {

		char * output = getCmdOption(argv, argv + argc, "-o");

		string gen_string = string(generate);
		cout << "Generating: " << gen_string;

		if (output)
		{


			string output_string = string(output);
			cout << "output: " << output_string << "\n";


			try
			{
				BundleGenerator generator;
				generator.generatePlanarGraphs(output_string);

			}
			catch (int e)
			{
			}

		}
		else {
			cout << "missing output (-o)";
			return (-1);
		}

		return (0);

	}

	char * convert = getCmdOption(argv, argv + argc, "-CONVERT");

	if (convert) {

		char * input = getCmdOption(argv, argv + argc, "-i");
		char * output = getCmdOption(argv, argv + argc, "-o");

		string conversion_string = string(convert);

		if (input && output)
		{
			string input_string = string(input);
			string output_string = string(output);

			try
			{
				Converter converter;
				if (conversion_string.compare("gml2dot") == 0) {
					converter.convertGMLToDOT(input, output);
				}
			}
			catch (int e)
			{
			}

		}
		else {
			cout << "missing input and output (-i -o)";
			return (-1);
		}

		return (0);


	}




	//string generatedGraphsfile = argv[1];
	//cout << generatedGraphsfile;
	//generatePlanarGraphs(generatedGraphsfile);

	/*
	if(argc != 3)
	{
		cout << "Missing parameter.\n Usage: INPUTFILE OUTPUTFILE";
		return (-1);
	}


	
	string filePath = argv[1];
	outputPath = argv[2];

	convertGMLToDOT(filePath);

	*/

	/*

	if(argc != 4)
	{
		cout << "Missing parameter.\n Usage: filePath outputhPath";
		return (-1);
	}



	string filePath = argv[1];
	string outputPath = argv[2];

	std::stringstream ss(argv[3]);
	bool planar = false;

	if(!(ss >> std::boolalpha >> planar)) {
		// Parsing error.
		cout << "error parsing Planar param";
	}

	cout << "Drawing: " << filePath << "\n";

	if (planar)
		cout << "using planar alg \n";
	else
		cout << "without using planar alg\n";

	try
	{
		Drawer drawer;
		drawer.computeDrawingForGraph(filePath, outputPath, false);

	}
	catch (int e)
	{}

	*/

	//system("pause");
	return 0;

}
//end of the main