#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "running_median.h"

TEST_CASE("Test using double with manually generated input and reference result")
{
	const int testCaseSize = 10;
	double inputSequence[testCaseSize] =   { 10.0, 20.0, 30.0,  5.0, 15.0, 25.0, -1.0, -2.0, -3.0, -4.0 };
	double referenceResult[testCaseSize] = { 10.0, 15.0, 20.0, 15.0, 15.0, 17.5, 15.0, 12.5, 10.0,  7.5 };

	RunningMedian<double> medianStreamer;

	for(int index = 0; index < testCaseSize; ++index){
		medianStreamer.add(inputSequence[index]);
		REQUIRE(medianStreamer.getMedian() == referenceResult[index]);
	}
}

TEST_CASE("Test using int with manually generated input and reference result")
{
	const int testCaseSize = 10;
	int inputSequence[testCaseSize] =   { 10, 20, 30,  5, 15, 25, -1, -2, -3, -4 };
	int referenceResult[testCaseSize] = { 10, 15, 20, 15, 15, 17, 15, 12, 10,  7 };

	RunningMedian<int> medianStreamer;

	for(int index = 0; index < testCaseSize; ++index){
		medianStreamer.add(inputSequence[index]);
		REQUIRE(medianStreamer.getMedian() == referenceResult[index]);
	}
}
