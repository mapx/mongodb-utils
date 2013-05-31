mongodb-utils
=============

Mongodb utilities.

<table>
  <tr><th colspan="2" style="text-align:center;">Improved BSONObj Builder Macros</th></tr>
  <tr>
    <td><code>BSONS</code></td>
    <td><p>A macro to build a BSONObj of custom initial buffer size from a stream to reduce memory allocation times.</p>
<p>e.g.,</p><p><code>BSONS(32, "name" &lt;&lt; "joe" &lt;&lt; "age" &lt;&lt; 33 )</code></p>
    <p>with auto-generated object id:</p>
       <p><code>BSONS(64, GENOID &lt;&lt; "name" &lt;&lt; "joe" &lt;&lt; "age" &lt;&lt; 33 )</code></p>
    <p>when size is 64, it is the same as:</p>
       <p><code>BSON(GENOID &lt;&lt; "name" &lt;&lt; "joe" &lt;&lt; "age" &lt;&lt; 33 )</code></p>
    <p>The labels GT, GTE, LT, LTE, NE can be helpful for stream-oriented construction
    of a BSONObj, particularly when assembling a Query.  For example,</p>
    <p><code>BSONS(96, "a" &lt;&lt; GT &lt;&lt; 23.4 &lt;&lt; NE &lt;&lt; 30 &lt;&lt; "b" &lt;&lt; 2 )</code> produces the object
    <code>{ a: { $gt: 23.4, $ne: 30 }, b: 2 }</code>.</p>
</td>
  </tr>
  <tr>
    <td><code>BSONS_ARRAY</code></td>
    <td><p>Use BSONS_ARRAY macro like BSONS macro, but without keys</p>
    <pre><code>BSONArray arr = BSONS_ARRAY(128, "hello" &lt;&lt; 1 &lt;&lt;
        BSON("foo" &lt;&lt; BSONS_ARRAY(32, "bar" &lt;&lt; "baz" &lt;&lt; "qux" ) ) );</code></pre>

  </td>
  </tr>
  <tr><th colspan="2" style="text-align:center;">Debug Helpers</th></tr>
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

