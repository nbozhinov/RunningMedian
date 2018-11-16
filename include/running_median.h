#include <queue>
#include <vector>
#include <functional>
#include <limits>

template<typename T>
class RunningMedian
{
private:
	// The numbers greater than the median. The smallest is on top
	std::priority_queue<T, std::vector<T>, std::greater<T> > upperHalf;
	// The numbers smaller than the median. The greatest is on top
	std::priority_queue<T, std::vector<T>, std::less<T> > lowerHalf;

public:
	RunningMedian(){
		// Seed the queues
		// IMPORTANT!!! Use lowest() instead of min() as with doubles sometimes the
		// priority_queue behaves wrong whit the  min() value.
		upperHalf.push(std::numeric_limits<T>::max());
		lowerHalf.push(std::numeric_limits<T>::lowest());
	}
	void add(T val) {

		//If number is greater than the least upper number, it is an upper number
		if(val >= upperHalf.top()){
			upperHalf.push(val);
		}else{
			lowerHalf.push(val);
		}

		//If the sizes of the two halves differ by more than 1 we need to balance them.
		if(upperHalf.size() - lowerHalf.size() == 2){
		//Move one number from upper half to lower half
			lowerHalf.push(upperHalf.top());
			upperHalf.pop();
		}else if(lowerHalf.size() - upperHalf.size() == 2){
		//Move one number from lower half to upper half
			upperHalf.push(lowerHalf.top());
			lowerHalf.pop();
		}
	}

	T getMedian() const {
		if(upperHalf.size() == lowerHalf.size()){
			return (upperHalf.top() + lowerHalf.top()) / T(2.0);
		}else if(upperHalf.size() > lowerHalf.size()){
			return upperHalf.top();
		}else{
			return lowerHalf.top();
		}
	}
};
