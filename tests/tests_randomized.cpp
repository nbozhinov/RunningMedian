#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <sstream>
#include <vector>
#include <random>
#include <algorithm>

#include "running_median.h"

template<typename T>
std::string printSequence(const std::vector<T>& inputSequence)
{
	std::stringstream ss;
	ss << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n";
	size_t testCaseSize = inputSequence.size();
	for(size_t index = 0; index < testCaseSize; ++index){
		ss << inputSequence[index] << " ";
	}
	ss << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n";

	// Always return false, as this is intended to be used only when a test fails.
	return ss.str();
}

TEST_CASE("Test using double with manually generated input and reference using sort")
{
	const int testCaseSize = 10;
	std::vector<double> inputSequence;

	// Create a sequence of random numbers.
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<double> dis(-1e6, 1e6); // use a limited range, so that we don't get overflows

	// Create an object of the class we are testing.
	RunningMedian<double> medianStreamer;

	for(int index = 0; index < testCaseSize; ++index){
		const double randomNumber = dis(gen);

		medianStreamer.add(randomNumber);
		inputSequence.push_back(randomNumber);

		// Sort the sequence and then find its median.
		std::sort(inputSequence.begin(), inputSequence.end());
		const double referenceResult = index % 2 == 0
			? inputSequence[index / 2]
			: (inputSequence[index / 2] + inputSequence[index / 2 + 1]) / 2.0;

		INFO(printSequence(inputSequence));
		REQUIRE(medianStreamer.getMedian() == referenceResult);
	}
}

TEST_CASE("Test using int with randomly generated input and reference using sort")
{
	const int testCaseSize = 1000;
	std::vector<int> inputSequence;

	// Create a sequence of random numbers.
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<int> dis(-1000000, 1000000); // use a limited range, so that we don't get overflows

	// Create an object of the class we are testing.
	RunningMedian<int> medianStreamer;

	for(int index = 0; index < testCaseSize; ++index){
		int randomNumber = dis(gen);

		medianStreamer.add(randomNumber);
		inputSequence.push_back(randomNumber);

		// Sort the sequence and then find its median.
		std::sort(inputSequence.begin(), inputSequence.end());
		int referenceResult = index % 2 == 0
			? inputSequence[index / 2]
			: (inputSequence[index / 2] + inputSequence[index / 2 + 1]) / 2;

		INFO(printSequence(inputSequence));
		REQUIRE(medianStreamer.getMedian() == referenceResult);
	}
}
