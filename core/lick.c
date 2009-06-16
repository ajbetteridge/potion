//
// lick.c
// the interleaved data format
//
// (c) 2008 why the lucky stiff, the freelance professor
//
#include <stdio.h>
#include <stdlib.h>
#include "potion.h"
#include "internal.h"

PN potion_lick(Potion *P, PN name, PN inner) {
  vPN(Lick) lk = PN_ALLOC(PN_TLICK, struct PNLick);
  lk->name = name;
  lk->inner = inner;
  return (PN)lk;
}

PN potion_lick_licks(Potion *P, PN cl, PN self) {
  PN licks = ((struct PNLick *)self)->inner;
  if (PN_IS_TUPLE(licks)) return licks;
  return PN_NIL;
}

PN potion_lick_name(Potion *P, PN cl, PN self) {
  return ((struct PNLick *)self)->name;
}

PN potion_lick_text(Potion *P, PN cl, PN self) {
  PN text = ((struct PNLick *)self)->inner;
  if (PN_IS_STR(text)) return text;
  return PN_NIL;
}

void potion_lick_init(Potion *P) {
  PN lk_vt = PN_VTABLE(PN_TLICK);
  potion_method(lk_vt, "licks", potion_lick_licks, 0);
  potion_method(lk_vt, "name", potion_lick_name, 0);
  potion_method(lk_vt, "text", potion_lick_text, 0);
}
