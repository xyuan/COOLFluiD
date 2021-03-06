#include "Framework/State.hh"
#include "Environment/ObjectProvider.hh"

#include "SpectralFD/SpectralFD.hh"
#include "SpectralFD/SetHexaLagrangeP2SpectralFDP3StateCoord.hh"

//////////////////////////////////////////////////////////////////////////////

using namespace std;

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace SpectralFD {

//////////////////////////////////////////////////////////////////////////////

Environment::ObjectProvider<SetHexaLagrangeP2SpectralFDP3StateCoord,
               Framework::SetElementStateCoord,
               SpectralFDModule>
SetHexaLagrangeP2SpectralFDP3StateCoord("HexaLagrangeP2SpectralFDP3");

//////////////////////////////////////////////////////////////////////////////

void SetHexaLagrangeP2SpectralFDP3StateCoord::operator() (const vector<Framework::Node*>& nodes,
                                         vector<Framework::State*>& states)
{
  cf_assert(states.size() == 64);
  cf_assert(nodes.size() == 27);
}

//////////////////////////////////////////////////////////////////////////////

void SetHexaLagrangeP2SpectralFDP3StateCoord::update(const vector<Framework::Node*>& nodes,
                                                     vector<Framework::State*>& states)
{
}

//////////////////////////////////////////////////////////////////////////////

  } // namespace ShapeFunctions

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////
