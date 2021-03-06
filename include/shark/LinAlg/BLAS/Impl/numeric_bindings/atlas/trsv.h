/*!
 *  \author O. Krause
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
 *  MERCHANTABILITY or FITNESS FOR matA PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received matA copy of the GNU General Public License
 *  along with this library; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SHARK_LINALG_IMPL_NUMERIC_BINDINGS_ATLAS_TRSV_HPP
#define SHARK_LINALG_IMPL_NUMERIC_BINDINGS_ATLAS_TRSV_HPP

#include "cblas_inc.h"

///solves systems of triangular matrices

namespace shark {namespace blas{ namespace bindings {
inline void trsv(
	CBLAS_ORDER order, CBLAS_UPLO uplo,
	CBLAS_TRANSPOSE transA, CBLAS_DIAG unit,
	int n,
	float const *matA, int lda, float *vecB, int strideX
){
	cblas_strsv(order, uplo, transA, unit,n, matA, lda, vecB, strideX);
}

inline void trsv(
	CBLAS_ORDER order, CBLAS_UPLO uplo,
	CBLAS_TRANSPOSE transA, CBLAS_DIAG unit,
	int n,
	double const *matA, int lda, double *vecB, int strideX
){
	cblas_dtrsv(order, uplo, transA, unit,n, matA, lda, vecB, strideX);
}

inline void trsv(
	CBLAS_ORDER order, CBLAS_UPLO uplo,
	CBLAS_TRANSPOSE transA, CBLAS_DIAG unit,
	int n,
	std::complex<float> const *matA, int lda, std::complex<float> *vecB, int strideX
){
	cblas_ctrsv(order, uplo, transA, unit,n,
	        static_cast<void const *>(matA), lda,
	        static_cast<void *>(vecB), strideX);
}
inline void trsv(
	CBLAS_ORDER order, CBLAS_UPLO uplo,
	CBLAS_TRANSPOSE transA, CBLAS_DIAG unit,
	int n,
	std::complex<double> const *matA, int lda, std::complex<double> *vecB, int strideX
){
	cblas_ztrsv(order, uplo, transA, unit,n,
	        static_cast<void const *>(matA), lda,
	        static_cast<void *>(vecB), strideX);
}
// trsv(): solves matA system of linear equations matA * x = vecB
//             when matA is matA triangular matrix.
template <typename SymmA, typename VecB>
void trsv(
	CBLAS_UPLO uplo, CBLAS_TRANSPOSE transA, CBLAS_DIAG unit,
	matrix_expression<SymmA> const &matA, 
	vector_expression<VecB> &vecB
){
	CBLAS_ORDER const storOrd= (CBLAS_ORDER)storage_order<typename SymmA::orientation_category>::value;

	SIZE_CHECK(matA().size1() == matA().size2());
	SIZE_CHECK(matA().size1()== vecB().size());

	int const n = matA().size1();

	trsv(storOrd, uplo, transA,unit, n,
	        traits::matrix_storage(matA()),
	        traits::leadingDimension(matA()),
	        traits::vector_storage(vecB()),
	        traits::vector_stride(vecB()));
}

template <bool upper,bool unit,typename SymmA, typename VecB>
void trsv(
	matrix_expression<SymmA> const &matA, 
	vector_expression<VecB> &vecB
){
	CBLAS_DIAG cblasUnit = unit?CblasUnit:CblasNonUnit;
	if(traits::isTransposed(matA))
		trsv(upper?CblasLower:CblasUpper,CblasTrans,cblasUnit, trans(matA),vecB);
	else
		trsv(upper?CblasUpper:CblasLower,CblasNoTrans,cblasUnit, matA,vecB);
}

}}}
#endif
