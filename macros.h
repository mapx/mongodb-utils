#ifndef MAPX_MONOGODB_MACROS_H
#define MAPX_MONOGODB_MACROS_H

#include <cassert>
#ifndef NDEBUG
#include <cstdio>
#endif

// where BSON and BOSN_ARRAY is defined
#include <bson/bsonmisc.h>

// for QUERYS macro
#include <mongo/client/dbclientinterface.h>


/** Use BSONS macro to build a BSONObj of custom initial buffer size from a stream
    to reduce memory allocation times.

    e.g.,
       BSONS(32, "name" << "joe" << "age" << 33 )

    with auto-generated object id:
       BSONS(64, GENOID << "name" << "joe" << "age" << 33 )
    when size is 64, it is the same as:
       BSON(GENOID << "name" << "joe" << "age" << 33 )

    The labels GT, GTE, LT, LTE, NE can be helpful for stream-oriented construction
    of a BSONObj, particularly when assembling a Query.  For example,
    BSONS(96, "a" << GT << 23.4 << NE << 30 << "b" << 2 ) produces the object
    { a: { \$gt: 23.4, \$ne: 30 }, b: 2 }.
*/
#define BSONS(size, x) (( mongo::BSONObjBuilder(size) << x ).obj())
#define QUERYS(size, x) mongo::Query( BSONS(size, x) )

/** Use BSONS_ARRAY macro like BSONS macro, but without keys

    BSONArray arr = BSONS_ARRAY(128, "hello" << 1 <<
        BSON("foo" << BSONS_ARRAY(32, "bar" << "baz" << "qux" ) ) );

 */
#define BSONS_ARRAY(size, x) (( mongo::BSONArrayBuilder(size) << x ).arr())


/**
 * Print bson::bob of the format:
 * __FILE__:__LINE__ bob[<buffer_size>]=<bob content>
 * Only available in DEBUG mode.
 * WARNING: expression b is calculated twice, which might have
 * side effects.
 */
#define SHOW_BSON_BOB(b) assert(printf("%s:%d bob[%d]=%s\n", \
      __FILE__, __LINE__, \
      (b).asTempObj().objsize(), \
      (b).asTempObj().jsonString().c_str()))


/**
 * Print bson::bo of the format:
 * __FILE__:__LINE__ bo[<buffer_size>]=<bo content>
 * Only available in DEBUG mode.
 * WARNING: expression b is calculated twice, which might have
 * side effects.
 */
#define SHOW_BSON_BO(b) assert(printf("%s:%d bo[%d]=%s\n", \
      __FILE__, __LINE__, \
      (b).objsize(), \
      (b).jsonString().c_str()))


/**
 * Print bson::be of the format:
 * __FILE__:__LINE__ be[<buffer_size>]=<be content>
 * Only available in DEBUG mode.
 * WARNING: expression b is calculated twice, which might have
 * side effects.
 */
#define SHOW_BSON_BE(b) assert(printf("%s:%d be[%d]=%s\n", \
      __FILE__, __LINE__, \
      (b).objsize(), \
      (b).toString().c_str()))

/**
 * Print LastError of mongodb connection.
 * Only available in DEBUG mode.
 */
#define SHOW_MONGODB_LASTERR(c) assert(printf("%s:%d lasterr=%s\n", \
      __FILE__, __LINE__, \
      (c).getLastErrorDetailed(false, true).jsonString().c_str()))
  
#endif

