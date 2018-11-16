/// @file running_median.h
/// @brief Contains a class for efficient computation of the median of a changing set of numbers.
/// @author Nikola Bozhinov

#pragma once

#include <queue>
#include <vector>
#include <functional>
#include <limits>

/// @class RunningMedian<T>
/// @brief A class for efficient computation of the median of a changing set of numbers.
/// The class uses two priority_queue-s to allow efficiency of both adding a new number and
/// and calculating the median of the currently added numbers. Those are the only two
/// supported operations.
/// @tparam T the type of the numbers
template<typename T>
class RunningMedian
{
private:
	// The numbers greater than the median. The smallest is on top
	std::priority_queue<T, std::vector<T>, std::greater<T> > upperHalf;
	// The numbers smaller than the median. The greatest is on top
	std::priority_queue<T, std::vector<T>, std::less<T> > lowerHalf;

public:
    /// @brief Default constructor.
    /// Initializes the two priority_queue-s with max() and lowest() for simplicity of implementation.
	RunningMedian(){
		// Initialize the queues with the two extreme values of the type, so that we don't
		// need to check for empty queues and can return something when getMedian() is called
		// but we don't have any numbers added yet.
		// IMPORTANT!!! Use lowest() instead of min() as with doubles sometimes the
		// priority_queue behaves wrong with the  min() value.
		upperHalf.push(std::numeric_limits<T>::max());
		lowerHalf.push(std::numeric_limits<T>::lowest());
	}

	/// @brief Adds a new number to the set of numbers.
    /// Adds the number and then balances the queues, so that each has exactly the half of the numbers.
    /// @param val the new value to add.
	void add(T val){
		//If number is greater than the least upper number, it is an upper number
		if(val >= upperHalf.top()){
			upperHalf.push(val);
		}else{
			lowerHalf.push(val);
		}

		// If the sizes of the two halves differ by more than 1 we need to balance them.
		// because the balancing is done on every addition the biggest difference we can have is 2.
		if(upperHalf.size() - lowerHalf.size() == 2){
            // Move one number from upper half to lower half
			lowerHalf.push(upperHalf.top());
			upperHalf.pop();
		}else if(lowerHalf.size() - upperHalf.size() == 2){
            // Move one number from lower half to upper half
			upperHalf.push(lowerHalf.top());
			lowerHalf.pop();
		}
	}

	/// @brief Calculates the median the current set of numbers.
    /// @return the current median.
	T getMedian() const {
		if(upperHalf.size() == lowerHalf.size()){
            // Equal number of elements in both halves - half the sum of their top()-s is the median.
			return (upperHalf.top() + lowerHalf.top()) / T(2.0); // Attention this can overflow.
		}else if(upperHalf.size() > lowerHalf.size()){
		    // One element more in the upper half - its top() is the median.
			return upperHalf.top();
		}else{
		    // One element more in the lower half - its top() is the median.
			return lowerHalf.top();
		}
	}
};
