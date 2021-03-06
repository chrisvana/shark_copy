/**
*
*  \brief Provides a function for estimating the kullback-leibler-divergence.
*
*  \author  O. Krause
*  \date    2010-01-01
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
*/
#ifndef SHARK_RNG_KULLBACK_LEIBER_DIVERGENCE_H
#define SHARK_RNG_KULLBACK_LEIBER_DIVERGENCE_H

#include <shark/Core/Exception.h>

namespace shark {

	/**
	* \brief Estimates the kullback-leibler-divergence between two distributions. The more trials the better is the estimate, but good estimates are slow.
	* \tparam DistributionP The type of distribution, needs to provide operator()() for sampling purposes.
	* \tparam DistributionQ The type of distribution, needs to provide operator()() for sampling purposes.
	* \param [in,out] p Distribution instance to sample from.
	* \param [in,out] q Distribution instance to sample from.
	* \param [in] trials The number of samples drawn from the distribution. Needs to be larger than 0.
	* \throws shark::Exception if trials == 0.
	*/
	template<typename DistributionP, typename DistributionQ>
	double kullback_leiber_divergence( DistributionP & p, DistributionQ & q, std::size_t trials = 10000 ) {
		if( trials == 0 )
			throw( shark::Exception( "kullback_leiber_divergence: Trial count needs to be larger than 0.", __FILE__, __LINE__ ) );

		double t( 0 );
		double x;
		for ( unsigned int i = 0; i < trials; i++ ) {
			x = p();
			t += ::log( p.p( x ) / q.p( x ) );
		}
		return( t / trials );
	}
}

#endif