cmake_minimum_required(VERSION 3.5)
project(trie VERSION 1.0.0 LANGUAGES C)

add_library(trie src/trie.c)
target_include_directories(trie PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

enable_testing()
add_executable(trie-test test/trie.c)
target_link_libraries(trie-test trie)
add_test(NAME trie COMMAND trie-test)

install(TARGETS trie EXPORT TrieTargets
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)
install(DIRECTORY include/trie DESTINATION include)
install(EXPORT TrieTargets
	FILE TrieTargets.cmake
	NAMESPACE Trie::
	DESTINATION lib/cmake/trie
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(TrieConfigVersion.cmake
	COMPATIBILITY SameMajorVersion
)

install(FILES build/TrieConfigVersion.cmake
	DESTINATION lib/cmake/trie
)

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
