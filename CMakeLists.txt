cmake_minimum_required(VERSION 3.17)
project(a89_915_Moldovan_Ioana)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_32/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(a89_915_Moldovan_Ioana
        domain.cpp
        domain.h
        repository.cpp
        repository.h
        service.cpp
        service.h
        main.cpp
        tests.cpp
        tests.h
        RepoExceptions.cpp RepoExceptions.h Validators.cpp Validators.h
        fileRepo.cpp
        fileRepo.h CSVRepo.cpp CSVRepo.h AdoptionList.cpp AdoptionList.h HTMLFile.cpp HTMLFile.h GUI.cpp GUI.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})