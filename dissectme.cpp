#include "config.h"

#include <epan/packet.h>
#include "dissectme.h"

#define DISSECTME_PORT 5000

void proto_register_dissectme(void);
void proto_reg_handoff_dissectme(void);
int dissect_dissectme(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_);

static int hf_dissectme_msg = -1;
static gint ett_dissectme = -1;
static int proto_dissectme = -1;

/*
static const value_string packettypenames[] = {
    {0, "Initialise"}
};
*/
/*
Each protocol must have a register function named proto_register_<protocol_name>
So some preprocessing might be needed during the cmake generation step(?), or during build(?)
Preprocessing will need to create the right proto_register_<name> and reg_handoff_<name>
functions, for this to work
All these proto_register_<name> functions will be extern "C" in the header, and will call
a cpp function with <name> passed as value
(probably can be done with macros)
*/
void proto_register_dissectme(void)
{
    static hf_register_info hf[] = {
        {
            &hf_dissectme_msg,
            {
                "msg",
                "dissectme.msg",
                FT_STRING,
                BASE_NONE,
                NULL, // VALS(packettypenames) for naming uint values in wireshark
                0x0,
                NULL,
                HFILL
            }
        }
    };

    // Setup protocol subtree array
    static gint *ett[] = {
        &ett_dissectme
    };

    // Name should be extracted from config file
    proto_dissectme = proto_register_protocol(
        "dissectme Protocol", // Name
        "dissectme", // Short name
        "dissectme" // filter name
    );

    proto_register_field_array(proto_dissectme, hf, array_length(hf));
    proto_register_subtree_array(ett, array_length(ett));
}

void proto_reg_handoff_dissectme(void)
{
    static dissector_handle_t dissectme_handle;
    dissectme_handle = create_dissector_handle(dissect_dissectme, proto_dissectme);
    dissector_add_uint("tcp.port", DISSECTME_PORT, dissectme_handle);
}

int dissect_dissectme(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_)
{
    col_set_str(pinfo->cinfo, COL_PROTOCOL, "DISSECTME");
    col_clear(pinfo->cinfo, COL_INFO);
    // Consume everything from 0 to -1(end)
    proto_item* ti = proto_tree_add_item(tree, proto_dissectme, tvb, 0, -1, ENC_NA);
    proto_tree* dissectme_tree = proto_item_add_subtree(ti, ett_dissectme);
    proto_tree_add_item(dissectme_tree, hf_dissectme_pdu_type, tvb, 0, 5, ENC_BIG_ENDIAN);
    return tvb_captured_length(tvb);
}
