
#include <common/interfaces/component.hh>
#include <common/interfaces/logging.hh>

namespace Magic
{
namespace Interfaces
{

Component* Component::s_instance = NULL;

Component::Component()
{
}

Component::~Component()
{
}

Component* Component::instance()
{
	if (Component::s_instance == NULL)
	{
		Component::s_instance = new Component();
	}
	
	return Component::s_instance;
}



}
}