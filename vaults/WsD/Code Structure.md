### 1. Connection with Wireshark
(The register/dissector/handoff functions need to be c compatible)

#### dissectme(.h|.cpp)
`void proto_register_dissectme(void)
(This will call into the main c++ code part of the dissector)
- Parse the kaitai file (if not compiled into the program)
- Use the title field in the following way:
	- name =  "`Kaitai struct.title`  Protocol"
	- short name = `Kaitai struct.title`
	- filter_name = lower(`Kaitai struct.title`)
`void proto_reg_handoff_dissectme(void)
(Same as the register, calls into the dissectors main c++ code)
- Create the dissector object, and when creating the dissector handle
pass the correct member function to it.
- If not possible give it a static member function, to which
  you bind an instance of the dissector object through partial

`int dissect_dissectme(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_)
This will do the actual dissecting, and also will call into the main c++ code, where the dissecting will be implemented.
- Create with proto_tree_add_item the base view in wireshark (If the endiannes given use ENC_BIG_ENDIAN or ENC_LITTLE_ENDIAN else ENC_NA)
- 


#TODO Experiment with the kaitai struct cpp runtime
#TODO Learn PlantUML and create diagrams instead of writing down everything in text

