#ifndef __MAGIC_INTERFACE_COMPONENT_H__
#define __MAGIC_INTERFACE_COMPONENT_H__

#include <string>

#include <common/common.hh>

namespace Magic
{
namespace Interfaces
{

class Component
{
	virtual ~Component();

	// Create the interface
	static Component* instance();

private:

	static Component* s_instance;

	Component();


};


}
}


#endif /* __MAGIC_INTERFACE_COMPONENT_H__ */
