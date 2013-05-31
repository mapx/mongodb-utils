mongodb-utils
=============

Mongodb utilities.

<table>
  <tr><th colspan="2" style="text-align:center;">Improved BSONObj builder macros</th></tr>
  <tr>
    <td><code>BSONS</code></td>
    <td><pre>Use BSONS macro to build a BSONObj of custom initial buffer size from a stream to reduce memory allocation times.

    e.g.,
       <code>BSONS(32, "name" << "joe" << "age" << 33 )</code>

    with auto-generated object id:
       <code>BSONS(64, GENOID << "name" << "joe" << "age" << 33 )</code>
    when size is 64, it is the same as:
       <code>BSON(GENOID << "name" << "joe" << "age" << 33 )</code>

    The labels GT, GTE, LT, LTE, NE can be helpful for stream-oriented construction
    of a BSONObj, particularly when assembling a Query.  For example,
    <code>BSONS(96, "a" << GT << 23.4 << NE << 30 << "b" << 2 )</code> produces the object
    <code>{ a: { $gt: 23.4, $ne: 30 }, b: 2 }.</code>
</pre>
</td>
  </tr>
  <tr>
    <td><code>BSONS_ARRAY</code></td>
    <td><pre>Use BSONS_ARRAY macro like BSONS macro, but without keys
    <code>BSONArray arr = BSONS_ARRAY(128, "hello" << 1 <<
        BSON("foo" << BSONS_ARRAY(32, "bar" << "baz" << "qux" ) ) );</code></pre>
  </td>
  </tr>
  <tr><th colspan="2" style="text-align:center;">Debug helpers</th></tr>
  <tr>
    <td><code>SHOW_BSON_BOB</code></td>
    <td>Print bson::bob object content only in DEBUG mode.</td>
  </tr>
  <tr>
    <td><code>SHOW_BSON_BO</code></td>
    <td>Print bson::bo object content only in DEBUG mode.</td>
  </tr>
  <tr>
    <td><code>SHOW_BSON_BE</code></td>
    <td>Print bson::be object content only in DEBUG mode.</td>
  </tr>
</table>

