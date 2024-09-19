cmake_minimum_required(VERSION 3.10)
project(Banking_Application_GTF_CPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_GENERATOR_PLATFORM x64)
set(BOOST_ROOT "C:/boost_1_86_0")

find_package(Boost)
# Set the path to MySQL Connector/C++ includes and libraries
include_directories("C:/Program Files/MySQL/MySQL Connector C++ 9.0/include" ${Boost_INCLUDE_DIRS})
link_directories("C:/Program Files/MySQL/MySQL Connector C++ 9.0/lib64/vs14")

# Add the executable
add_executable(Banking_Application_GTF_CPP main.cpp)

# Link against MySQL Connector C++ (dynamic linking) and necessary system libraries
target_link_libraries(Banking_Application_GTF_CPP
        "C:/Program Files/MySQL/MySQL Connector C++ 9.0/lib64/vs14/mysqlcppconn.lib"   # Dynamic linking
        "C:/Program Files/MySQL/MySQL Connector C++ 9.0/lib64/vs14/mysqlcppconnx.lib"  # Dynamic linking for X DevAPI

        # Only include OpenSSL libraries if needed (and only the dynamic versions)
        "C:/Program Files/MySQL/MySQL Connector C++ 9.0/lib64/vs14/libcrypto.lib"
        "C:/Program Files/MySQL/MySQL Connector C++ 9.0/lib64/vs14/libssl.lib"

        #boost
        ${Boost_LIBRARIES}

        # System libraries
        kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32


)