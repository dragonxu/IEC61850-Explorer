/// @author Cedric Boudinet
/// @license GNU GPL Version 3
///
/// Distributed under the GNU GPL version 3 License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/)
///
#ifndef MMSVALUEWRAPPER_H
#define MMSVALUEWRAPPER_H
#include <libiec61850/iec61850_client.h>
#include <string>

class MmsValueWrapper
{
	public:
		MmsValueWrapper(const std::string & variableName, FunctionalConstraint, MmsType);
		std::string getDispName();
	private:
		std::string _variableName;
		FunctionalConstraint _fc;
		MmsType _mmstype;
};
#endif