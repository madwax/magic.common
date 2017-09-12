#ifndef __MAGIC_LOGGING_INTERFACE_H__
#define __MAGIC_LOGGING_INTERFACE_H__

#include "common/common.hh"

namespace Magic
{
namespace Interfaces
{
typedef enum 
{
	Fatal = 0,
	Report,
	Error,
	Warning,
	Info,
	Debug,
} GeneralLoggingLevels;


typedef enum 
{
	IOReport = 0,
	IOError,
	IOWarning,
	IORaw,
	IOInfo,
	IODebug
} IOLoggingLevels;

class Logging
{
public:
	virtual ~Logging();

	static Logging* instance();

	void setGeneralLevel( Magic::Interfaces::GeneralLoggingLevels toLevel );
	void setIOLevel( Magic::Interfaces::IOLoggingLevels toLevel );

	void logGeneral( Magic::Interfaces::GeneralLoggingLevels level, const char *msg );
	void logIO( Magic::Interfaces::IOLoggingLevels level, const char *msg );

private:
	static Logging* s_instance;

	// The different logging levels.
	Magic::Interfaces::GeneralLoggingLevels m_generalLevel;
	Magic::Interfaces::IOLoggingLevels m_ioLevel;
	
	Logging();
};

}
}


#endif /* __MAGIC_LOGGING_INTERFACE_H__ */