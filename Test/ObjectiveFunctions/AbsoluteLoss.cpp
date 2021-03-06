//===========================================================================
/*!
 *  \file AbsoluteLoss.cpp
 *
 *  \brief Absolute loss test case
 *
 *
 *  \author T. Glasmachers
 *  \date 2011
 *
 *  \par Copyright (c) 1998-2011:
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

#include <shark/ObjectiveFunctions/Loss/AbsoluteLoss.h>
#include <cmath>

#include <shark/ObjectiveFunctions/ErrorFunction.h>
#include <shark/Models/LinearModel.h>
#include <shark/Rng/GlobalRng.h>

#define BOOST_TEST_MODULE OBJECTIVEFUNCTIONS_ABSOLUTELOSS
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

using namespace shark;

BOOST_AUTO_TEST_CASE( ABSOLUTELOSS_EVAL ) {
	AbsoluteLoss<> loss;
	unsigned int maxTests = 1000;
	unsigned int batchSize = 10;
	for (unsigned int test = 0; test != maxTests; ++test)
	{
		std::size_t dim = Rng::discrete(5, 100);
		RealMatrix target(batchSize,dim);
		RealMatrix output(batchSize,dim);
		double sum = 0;
		for(std::size_t b = 0; b != batchSize; ++b){
			double dist2 = 0;
			for (std::size_t d=0; d != dim; d++){
				target(b,d) = Rng::gauss();
				output(b,d) = Rng::gauss();
				double diff = target(b,d) - output(b,d);
				dist2 += diff * diff;
			}
			sum += std::sqrt(dist2);
		}
		
		double l = loss.eval(target, output);
		BOOST_CHECK_SMALL(l - sum, 1e-12);
	}
}
