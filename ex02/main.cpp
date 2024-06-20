#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac <= 2)
		return (0);
	if (av_check(av) == false)
		return (1);
	
	std::vector<int> mVec_o;
	generate(mVec_o, av);
	std::vector<std::pair<int, int> > mVec;
	for (unsigned int i = 0; i < mVec_o.size(); i++)
		mVec.push_back(std::make_pair(mVec_o[i], i));
	std::deque<int> dmVec_o;
	dgenerate(dmVec_o, av);
	std::deque<std::pair<int, int> > dmVec;
	for (unsigned int i = 0; i < dmVec_o.size(); i++)
		dmVec.push_back(std::make_pair(mVec_o[i], i));

	time_t start, end;

	std::cout << "Before: ";
	// mVecPrint(mVec);
    
	start = clock();
	mmerge(mVec);
	end = clock();
	
	std::cout << "After: ";
	// mVecPrint(mVec);

	std::cout << "Time to process a range of: "
        << mVec.size() << " elements with vector : " 
        << (end - start) << " us" << std::endl;
	
	std::cout << "\n\n\n\n\n" << std::endl;

	std::cout << "Before: ";
	// dmVecPrint(dmVec);
    
	start = clock();
	dmmerge(dmVec);
	end = clock();
	
	std::cout << "After: ";
	// dmVecPrint(dmVec);

	std::cout << "Time to process a range of: "
        << dmVec.size() << " elements with vector : " 
        << (end - start) << " us" << std::endl;

}
