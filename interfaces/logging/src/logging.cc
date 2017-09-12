#include "common/interfaces/logging.hh"

namespace Magic
{
namespace Interfaces
{

Logging* Logging::s_instance = NULL;

Logging::Logging() : m_generalLevel( Magic::Interfaces::GeneralLoggingLevels::Warning ), m_ioLevel( Magic::Interfaces::IOLoggingLevels::IORaw )
{
}

Logging::~Logging()
{
}

Logging* Logging::instance()
{
	if( Logging::s_instance == NULL )
	{
		Logging::s_instance = new Logging();
	}
	return Logging::s_instance;
}

void Logging::setGeneralLevel( Magic::Interfaces::GeneralLoggingLevels toLevel )
{
	m_generalLevel = toLevel;
}

void Logging::setIOLevel( Magic::Interfaces::IOLoggingLevels toLevel )
{
	m_ioLevel = toLevel;
}

void Logging::logGeneral( Magic::Interfaces::GeneralLoggingLevels level, const char *msg )
{
	if( level >= m_generalLevel )
	{
		return;
	}
	printf( "General:%d - %s\n", level, msg );
}

void Logging::logIO( Magic::Interfaces::IOLoggingLevels level, const char *msg )
{
	if( level >= m_ioLevel )
	{
		return;
	}
	printf( "IO:%d - %s\n", level, msg );
}
	
}
}