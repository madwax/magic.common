
#include <common/component_application.hh>

namespace Magic
{
namespace Common
{

ComponentApplication::ComponentApplication()
{
}

ComponentApplication::~ComponentApplication()
{
}

int ComponentApplication::parseCommandLine(int argv, char **argc)
{
	return 0;
}

const std::string& ComponentApplication::documentPath() const
{
	return m_documentPath;
}

const std::string& ComponentApplication::stationId() const
{
	return m_stationId;
}

const std::string& ComponentApplication::instanceId() const
{
	return m_instanceId;
}




}
}