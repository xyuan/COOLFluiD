// Copyright (C) 2012 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef COOLFluiD_Physics_RotationAdv_RotationAdv2DPrim_hh
#define COOLFluiD_Physics_RotationAdv_RotationAdv2DPrim_hh

//////////////////////////////////////////////////////////////////////////////

#include "RotationAdv2DVarSet.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Physics {

    namespace RotationAdv {
      

//////////////////////////////////////////////////////////////////////////////

/**
 * This class represents a RotationAdv physical model 2D for conservative
 * variables
 *
 * @author Tiago Quintino
 * @author Andrea Lani
 *
 */
class RotationAdv2DPrim : public RotationAdv2DVarSet {
public:
  /**
   * Constructor
   * @see RotationAdv2D
   */
  RotationAdv2DPrim(Common::SafePtr<Framework::BaseTerm> term);

  /**
   * Default destructor
   */
  virtual ~RotationAdv2DPrim();

  /**
   * Gets the average advection vector the specified variable
   * @param vec the vector to change
   * @param iVar the variable corresponding to the specified vector
   */
  virtual void getAverageAdvectionVector(RealVector& vec, const CFuint iVar) const;

  /**
   * Set the jacobians
   */
  virtual void computeJacobians();

  /**
   * Set the scalar part of the jacobian
   */
  virtual void computeScalarJacobian(const RealVector& normal, RealVector& jacob);

  /**
   * Set the matrix of the right eigenvectors and the matrix of the eigenvalues
   */
  virtual void computeEigenValuesVectors( RealMatrix& rightEv,
                                          RealMatrix& leftEv,
                                          RealVector& eValues,
                                          const RealVector& normal);

  /**
   * Set the PhysicalData corresponding to the given State
   * @see EulerPhysicalModel
   */
  /// @todo broken after release 2009.3 (added "const")
  void computePhysicalData(const Framework::State& state, RealVector& data);

   /// Set a State starting from the given PhysicalData
   //  /// @see EulerPhysicalModel
      void computeStateFromPhysicalData(const RealVector& data,
                         Framework::State& state);



}; // end of class RotationAdv2DPrim

//////////////////////////////////////////////////////////////////////////////

    } // namespace RotationAdv

  } // namespace Physics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Physics_RotationAdv_RotationAdv2DPrim_hh
