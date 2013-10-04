//===========================================================================
/*!
 *
 *  \brief Base class for constraints.
 *  \author O.Krause
 *  \date 2013
 *
 *  \par Copyright (c) 1998-2007:
 *      Institut f&uuml;r Neuroinformatik<BR>
 *      Ruhr-Universit&auml;t Bochum<BR>
 *      D-44780 Bochum, Germany<BR>
 *      Phone: +49-234-32-25558<BR>
 *      Fax:   +49-234-32-14209<BR>
 *      eMail: Shark-admin@neuroinformatik.ruhr-uni-bochum.de<BR>
 *      www:   http://www.neuroinformatik.ruhr-uni-bochum.de<BR>
 *      <BR>
 *
 *
 *  <BR><HR>
 *  This file is part of Shark. This library is free software;
 *  you can redistribute it and/or modify it under the terms of the
 *  GNU General Public License as published by the Free Software
 *  Foundation; either version 3, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this library; if not, see <http://www.gnu.org/licenses/>.
 *
 */
//===========================================================================
#ifndef SHARK_OBJECTIVEFUNCTIONS_ABSTRACTCONSTRAINTHANDLER_H
#define SHARK_OBJECTIVEFUNCTIONS_ABSTRACTCONSTRAINTHANDLER_H

#include <shark/Core/Exception.h>
#include <shark/Core/Factory.h>
#include <shark/Core/Flags.h>

namespace shark{


/// \brief Implements the base class for constraint handling.
///
/// A constraint handler provides information about the feasible region of a constrained optimization problem.
/// In the minimum it checks whether a point is feasible, or what the next fasible point would be.
template<class SearchPointType>
class AbstractConstraintHandler{
public:
	enum Feature {
		CAN_PROVIDE_CLOSEST_FEASIBLE     = 1,	///< The constraint handler can provide a close feasible point to an infeasible one
		IS_BOX_CONSTRAINED = 2,  ///< The constraint handler is an instance of BoxConstraintHandler
		CAN_GENERATE_RANDOM_POINT = 4  ///< The ConstraintHandler can generate a random point inside the feasible region
	};
	SHARK_FEATURE_INTERFACE;
	
	virtual ~AbstractConstraintHandler(){}
		
	/// \brief Returns whether this function can calculate the closest feasible to an infeasible point.
	bool canProvideClosestFeasible()const{
		return m_features & CAN_PROVIDE_CLOSEST_FEASIBLE;
	}
	
	/// \brief Returns whether this function is an instance of BoxConstraintHandler
	bool isBoxConstrained()const{
		return m_features &IS_BOX_CONSTRAINED;
	}
	/// \brief Returns whether this function is an instance of BoxConstraintHandler
	bool canGenerateRandomPoint()const{
		return m_features & CAN_GENERATE_RANDOM_POINT;
	}
	
	/// \brief If supported, generates a random point inside the feasible region.
	virtual void generateRandomPoint( SearchPointType & startingPoint )const {
		SHARK_FEATURE_EXCEPTION(CAN_GENERATE_RANDOM_POINT);
	}
	
	/// \brief Returns true if the point is in the feasible Region.
	///
	/// This function must be implemented by a ConstraintHandler
	virtual bool isFeasible(SearchPointType const&)const = 0;
	virtual void closestFeasible(SearchPointType& )const{
		SHARK_FEATURE_EXCEPTION(CAN_PROVIDE_CLOSEST_FEASIBLE );
	}
	
};
}
#endif