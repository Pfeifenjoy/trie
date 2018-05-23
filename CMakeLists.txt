cmake_minimum_required(VERSION 3.10)
project(trie VERSION 0.0.1 LANGUAGES C)

add_library(trie src/trie.c)
target_include_directories(trie PUBLIC include)

enable_testing()
add_executable(trie-test test/trie.c)
target_link_libraries(trie-test trie)
add_test(NAME trie COMMAND trie-test)

#CPack
set(CPACK_PACKAGE_CONTACT "arwed.mett@googlemail.com")

if(APPLE)
	set(CPACK_GENERATOR "TGZ;ZIP;productbuild")
elseif(UNIX)
	set(CPACK_GENERATOR "TGZ;ZIP;RPM;DEB")
elseif(WIN32)
	set(CPACK_GENERATOR "ZIP;NSIS;NSIS64")
else()
	set(CPACK_GENERATOR "TGZ;ZIP")
endif()

set(CPACK_BUNDLE_NAME ${PROJECT_NAME})
include(CPack)
