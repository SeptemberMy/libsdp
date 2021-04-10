/* 
 *  @BEGIN LICENSE
 * 
 *  libsdp: a c++ library for solving semidefinite programs
 * 
 *  Copyright (c) 2021 by its authors (LICENSE).
 * 
 *  The copyrights for code used from other parties are included in
 *  the corresponding files.
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 * 
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/.
 * 
 *  @END LICENSE
 */

#ifndef CG_SOLVER_H
#define CG_SOLVER_H

namespace libsdp{

typedef void (*CGCallbackFunction)(SharedVector,SharedVector,void *);  

class CGSolver {
public:

    CGSolver(long int n);
    ~CGSolver();
    void solve(double * Ap,
               double *  x,
               double *  b,
               CGCallbackFunction function, void * data);

    int total_iterations();
    void set_max_iter(int iter);
    void set_convergence(double conv);

private:

    int    n_;
    int    iter_;
    int    cg_max_iter_;
    double cg_convergence_;
    double * p_;
    double * r_;

};

} // end of namespace

#endif
