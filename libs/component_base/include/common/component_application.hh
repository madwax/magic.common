#ifndef __MAGIC_COMMON_COMPONENT_APPLICATION_H__
#define __MAGIC_COMMON_COMPONENT_APPLICATION_H__

#include <common/common.hh>

#include <common/interfaces/component.hh>
#include <common/interfaces/logging.hh>

#include <string>

namespace Magic
{
namespace Common
{

class ComponentApplication
{
public:
	ComponentApplication();
	virtual ~ComponentApplication();

	virtual int parseCommandLine(int argv, char **argc);

	const std::string& documentPath() const;
	const std::string& stationId() const;
	const std::string& instanceId() const;

private:
	/// were the doc is.
	std::string m_documentPath;
	/// the id for the station this instance belongs to.
	std::string m_stationId;
	/// the id of this running instance.
	std::string m_instanceId;

	/// The entry point of the app.
	virtual int run() = 0;

}; 

}
}

#endif /* __MAGIC_COMMON_COMPONENT_APPLICATION_H__ */
