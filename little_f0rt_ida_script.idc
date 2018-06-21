#include <idc.idc>

static main()
{
  auto _GLOBAL_OFFSET_TABLE_ = get_name_ea_simple("_GLOBAL_OFFSET_TABLE_");
  auto virtualalloc = get_name_ea_simple("virtualalloc");
  auto heapfree = get_name_ea_simple("heapfree");
  auto INFINITE = get_name_ea_simple("INFINITE");
  auto writememory = get_name_ea_simple("writememory");
  auto heapalloc = get_name_ea_simple("heapalloc");
  auto waitforsingelobject = get_name_ea_simple("waitforsingelobject");
  
  auto First = 0x41;
  auto Second = 0x43;
  auto Third = 0x45;
  
  xor(_GLOBAL_OFFSET_TABLE_, First);
  xor(virtualalloc, Second);
  xor(heapfree, Third);
  xor(INFINITE, Third);
  xor(writememory, Second);
  xor(heapalloc, First);
  xor(waitforsingelobject, Second);
  xor(remotethread, Third);
  Message("\n");
}

static xor(StartAddress, Key)
{
 auto i;
 for(i=0;i<8;i++)
 {
  auto MyByte = get_wide_byte(StartAddress+i);
  MyByte = MyByte ^ Key;
  Message(MyByte);
 }
}
