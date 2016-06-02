/// @author Cedric Boudinet
/// @license GNU GPL Version 3
///
/// Distributed under the GNU GPL version 3 License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/)
#include "MmsValueWrapper.h"

MmsValueWrapper::MmsValueWrapper(const std::string & varName, FunctionalConstraint fc, MmsType varType) :
	_variableName(varName), _fc(fc), _mmstype(varType) { }

std::string MmsValueWrapper::getDispName()
{
	return (_variableName+ " ["+FunctionalConstraint_toString(_fc)+"]").c_str();
}

std::string MmsValueWrapper::getValueAsString(IedConnection IedCon)
{
	IedClientError error; //TODO : handle read error
	MmsValue * myMms;
	char buffer[100];
	myMms = IedConnection_readObject(IedCon, &error, _variableName.c_str(), _fc);
	std::string ret = MmsValue_printToBuffer(myMms, buffer, 100);
	MmsValue_delete(myMms);
	return ret;
}

float MmsValueWrapper::getValueAsFloat(IedConnection IedCon)
{
	IedClientError error; //TODO : handle read error
	return IedConnection_readFloatValue(IedCon, &error, _variableName.c_str(), _fc);
}

void MmsValueWrapper::setFloatValue(IedConnection IedCon, float newVal)
{
	IedClientError error; //TODO : handle read error
	return IedConnection_writeFloatValue(IedCon, &error, _variableName.c_str(), _fc, newVal);
}

MmsType MmsValueWrapper::getType()
{
	return _mmstype;
}
