#ifndef COOLFluiD_Physics_SA_Euler3DSAPvtToCons_hh
#define COOLFluiD_Physics_SA_Euler3DSAPvtToCons_hh

//////////////////////////////////////////////////////////////////////////////

#include "Framework/VarSetTransformer.hh"
#include "Framework/MultiScalarTerm.hh"
#include "NavierStokes/EulerTerm.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Physics {

    namespace SA {

//////////////////////////////////////////////////////////////////////////////

/**
 * This class represents a transformer of variables from primitive
 * [p u v w T Nuitil] to conservative variables [rho rhoU rhoV rhoW rhoE rhoNuitil]
 *
 * @author Joao Pinto
 * @author Thomas Wuilbaut
 * @modified Christos Gkoudesnes
 *
 */
class Euler3DSAPvtToCons : public Framework::VarSetTransformer {
public:

  typedef Framework::MultiScalarTerm<NavierStokes::EulerTerm> EulerSATerm;
  
  /**
   * Constructor
   */
  Euler3DSAPvtToCons(Common::SafePtr<Framework::PhysicalModelImpl> model);

  /**
   * Default destructor
   */
  ~Euler3DSAPvtToCons();
  
  /**
   * Transform a state into another one
   */
  void transform(const Framework::State& state, Framework::State& result);
  
  /**
   * Transform a state into another one from reference precomputed
   * values (physical data)associated to the given state
   */
  void transformFromRef(const RealVector& data, Framework::State& result);

private:

  /// acquaintance of the PhysicalModel
  Common::SafePtr<EulerSATerm> _model;

}; // end of class Euler3DSAPvtToCons

//////////////////////////////////////////////////////////////////////////////

    } // namespace SA

  } // namespace Physics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Physics_SA_Euler2DSAPvtToCons_hh
