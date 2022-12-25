(NOTE: once the first version is done, convert this into a README.md)
### 0. [[Code Structure]]
The user just has to create a kaitai based config file explaining the dissector the
field <-> datatype relations.
The dissector should not need anything else for its workings.

### 1. [[Kaitai based configuration]]
Study [https://doc.kaitai.io/user_guide.html](https://doc.kaitai.io/user_guide.html "https://doc.kaitai.io/user_guide.html")

### 2. Possibility to build config file with the project
For performance improvement. Modification to the build system will be needed.
If the build system files a config file, it inserts it after some transformation (which a python script will do), into the cpp file (std::map or something similar).
Study cmake docs for this. https://cmake.org/documentation/

### 3. Optimization with Intel Avx2
Look into what exactly do you get, and when in the dissector functions from wireshark. (Finding good docs for this will be hard, so trial and error the current best bet.)
https://www.wireshark.org/docs/wsdg_html_chunked/index.html

### 4. Change tracking of the config file
It should be possible to check during runtime any changes in the config file, and reload it. (In case the config file wasn't built into the lib directly.)

### 5. Encrypted fields parsing
Static link openssl to the program. There should be no problems with openssl since it is gpl 3 compatible.
It should be possible to give encrypted fields, resulting in the appropriate openssl 

### 6. Optional security features
(Could disable them during build, if one only runs data on trusted pcaps)
- Malformed data check (Malformed pcaps could potentially cause harm on the machine, if possible arbitary code execution etc. vulnerabilities aren't addressed)
- Look into other dissector code, and maybe ask around in the wireshark community, what should be checked on dissector side, and what is checked, by wiresharks internal code