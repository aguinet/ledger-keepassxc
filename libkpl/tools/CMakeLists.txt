add_library(tools_utils STATIC
  utils.cpp)
target_link_libraries(tools_utils PUBLIC kpl)

add_executable(kpl_set
  set.cpp)
target_link_libraries(kpl_set PRIVATE tools_utils)

add_executable(kpl_get
  get.cpp)
target_link_libraries(kpl_get PRIVATE tools_utils)

add_executable(kpl_derive
  derive.cpp)
target_link_libraries(kpl_derive PRIVATE tools_utils)

add_executable(kpl_get_slots
  get_slots.cpp)
target_link_libraries(kpl_get_slots PRIVATE tools_utils)

add_executable(kpl_list_devices
  list_devices.cpp)
target_link_libraries(kpl_list_devices PRIVATE tools_utils)

add_executable(kpl_erase_all_slots
  erase_all_slots.cpp)
target_link_libraries(kpl_erase_all_slots PRIVATE tools_utils)

install(TARGETS
  kpl_set kpl_get kpl_derive kpl_get_slots kpl_list_devices kpl_erase_all_slots
  RUNTIME
  DESTINATION bin)
