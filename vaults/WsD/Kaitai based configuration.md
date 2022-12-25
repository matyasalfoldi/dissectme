https://github.com/kaitai-io/kaitai_struct_cpp_stl_runtime
Can this be even used to read in a .ksy file?
https://doc.kaitai.io/lang_cpp_stl.html

### 1. Fixed-size structures implementation

#### Reading in the config file
The initial reading process should be done, by some yaml parser lib, that is gpl 3 compatible.

#### Needed functionality (ver 0.1)
- Be able to translate a kaitai seq
- Be able to translate the meta block
- Be able to translate the enums block

#### Later version functionality (ver 0.2)
- Be able to translate the types block
- Be able to translate type switching based on expression
- Be able to translate do nothing (dummy) type (switching based expression is a prereq)
- Be able to translate variable-size structures

#### Must have functionality for later
- Limiting total size of structure allowance

#### Good to have
- Be able to translate repeating until expressions

#### Open Questions
- Should we use the encoding filed for specifying the encryption, or should we use a custom extra field, that is not in kaitai. (TODO: check if there is a standard way of specifying such info)
