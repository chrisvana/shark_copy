// Shark
[
  { "cmake": {
    "name": "shark_cmake",
    "cmake_args" : [ "-DBOOST_ROOT=\"$ROOT_DIR/$BOOST_ROOT\"",
                     "-DBOOST_LIBRARYDIR=\"$ROOT_DIR/$BOOST_LIBDIR\"",
                     "-DBoost_NO_SYSTEM_PATHS=TRUE"
    ],
    "dependencies": [ "../boost:boost" ],
    "outs": [ "$GEN_DIR/build/lib/libshark.a" ]
  } },
  { "cc_library": {
      "name": "shark",
      "strict_file_mode": false,
      "cc_objects": [ "$GEN_DIR/build/lib/libshark.a" ],
      "header_compile_args": [ "-I$SRC_DIR/include",
                               "-Wno-error=null-conversion",
                               "-Wno-null-conversion",
                               "-Wno-error=unused-variable"
       ],
      "dependencies": [ ":shark_cmake" ]
  } }
]
