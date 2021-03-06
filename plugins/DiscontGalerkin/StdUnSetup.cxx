#include "Framework/MethodCommandProvider.hh"

#include "DiscontGalerkin/StdUnSetup.hh"
#include "DiscontGalerkin/DiscontGalerkin.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {
  namespace DiscontGalerkin {

//////////////////////////////////////////////////////////////////////////////

Framework::MethodCommandProvider< StdUnSetup,DiscontGalerkinSolverData,DiscontGalerkinModule >
  stdUnSetupProvider("StdUnSetup");

//////////////////////////////////////////////////////////////////////////////

void StdUnSetup::execute()
{
  CFAUTOTRACE;
}

//////////////////////////////////////////////////////////////////////////////

  }  // namespace DiscontGalerkin
}  // namespace COOLFluiD

