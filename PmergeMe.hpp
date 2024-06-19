/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:45:45 by qdo               #+#    #+#             */
/*   Updated: 2024/06/19 11:59:07 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGMEME_HPP

template <typename T, typename T2>
class PmergeMe : std::vector<T>
{
	private:
	public:
		~PmergeMe();
		PmergeMe();
		PmergeMe(PmergeMe & src);
		PMergeMe & operator=(PmergeMe & src);
		bool	isIntVector()
		{
			std::vector<int> *check = dynamic_cast<std::vector<int> >(*this);
			if (check != NULL)
				return (true);
			return (false);
		}
		std::vector<int> & firstIntVec()
		{
			if (this->isIntVector())
				return (*this);
			else
			{
				std::vector<T2> & thisFirstVec = this.begin();
				return (thisFirstVec.firstIntVec());
			}
		}
		bool operator>(PmergeMe &src)
		{
			std::vector<int> thisIntVec = this->firstIntVec;
			std::vector<int> srcIntVec = src->firstIntVec;
			if (this.begin() > src.begin())
				return (true);
			return (false);
		}
		bool operator<(PmergeMe &src)
		{
			std::vector<int> thisIntVec = this->firstIntVec;
			std::vector<int> srcIntVec = src->firstIntVec;
			if (this.begin() < src.begin())
				return (true);
			return (false);
		}
		bool operator>=(PmergeMe &src)
		{
			std::vector<int> thisIntVec = this->firstIntVec;
			std::vector<int> srcIntVec = src->firstIntVec;
			if (this.begin() >= src.begin())
				return (true);
			return (false);
		}
		bool operator<=(PmergeMe &src)
		{
			std::vector<int> thisIntVec = this->firstIntVec;
			std::vector<int> srcIntVec = src->firstIntVec;
			if (this.begin() <= src.begin())
				return (true);
			return (false);
		}
		bool operator==(PmergeMe &src)
		{
			std::vector<int> thisIntVec = this->firstIntVec;
			std::vector<int> srcIntVec = src->firstIntVec;
			if (this.begin() == src.begin())
				return (true);
			return (false);
		}
};

#endif