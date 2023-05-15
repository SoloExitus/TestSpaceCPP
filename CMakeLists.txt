# Минимальная версия CMake
cmake_minimum_required(VERSION 3.8)

# Предпочтительно следовать стандартам принятым в указанном диапазоне версий
cmake_policy(VERSION 3.0.2..3.7)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Название и версия проекта и используемые языки программирования
project(TestSite VERSION 1.0.0 LANGUAGES CXX)

set(cpp
	main.cpp
	testConsts1.cpp
	testConsts2.cpp
 )

set(hpp 
	constants.hpp
	testConsts.hpp
	testMove.hpp
)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (TestSite ${cpp} ${hpp})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TestSite PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
