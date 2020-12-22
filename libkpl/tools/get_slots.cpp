#include <kpl/ledger_device.h>
#include <kpl/kpl.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

int main(int argc, char** argv)
{
  auto Dev = kpl::LedgerDevice::getFirstDevice();
  if (!Dev) {
    fprintf(stderr, "Unable to find a Ledger device!\n");
    return 1;
  }
  fprintf(stderr, "Using device '%s'\n", Dev->name().c_str());
  kpl::Version AppVer;
  auto EKPL = kpl::KPL::fromDevice(*Dev, AppVer);
  if (!EKPL) {
    fprintf(stderr, "Error while initializing connection: %d!\n", EKPL.errorValue());
    return 1;
  }
  auto& KPL = EKPL.get();

  std::vector<uint8_t> Slots;
  auto Res = KPL.getValidKeySlots(Slots);
  if (Res != kpl::Result::SUCCESS) {
    fprintf(stderr, "Unable to get slots: %d!\n", Res);
    return 1;
  }
  if (Slots.size() == 0) {
    puts("No valid slots!");
    return 0;
  }
  for (uint8_t S: Slots) {
    printf("%d ", S);
  }
  printf("\n");
  return 0;
}