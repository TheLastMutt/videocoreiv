
  START("alpha.bin");
  
  declare(loop1);

  add(r4, r0);
  movi(r5, 0x0020);

label(loop1);
  // vld HX(y:0)y=16++ f, 0(r2+=r5) REP8 ; x=1 A=380 y=7 z=0 u=0
  vld80(W16, HXy0, 16, INC, 0, r2, r5, REP8);
  // vld HX(y:0)y=32++ f, 0(r3+=r5) REP8 ; x=1 A=380 y=7 z=0
  vld80(W16, HXy0, 32, INC, 0, r3, r5, REP8);
  // vld HX(y:0)y=0++ f, 0(r1+=r5) REP8 ; x=1 A=380 y=7 z=0
  vld80(W16, HXy0, 0, INC, 0, r1, r5, REP8);
  // vrmulmd H(y:0)y=16++ f, H(y:0)y=16++ f, H(y:0)y=32++ f REP8
  vr80(v_mulmd, Hy0, 16, INC, Hy0, 16, INC, Hy0, 32, INC, REP8);
  // vrmulmd H(y:16)y=16++ f, H(y:16)y=16++ f, H(y:16)y=32++ f REP8   #0 0
  vr80(v_mulmd, Hy16, 16, INC, Hy16, 16, INC, Hy16, 32, INC, REP8);
  //virsub HX(y:0)y=32++ f, HX(y:0)y=32++ f, #65535 REP8   #0 0
  vi80(v_rsub, HXy0, 32, INC, HXy0, 32, INC, 65535, REP8);
  // vrmulmd H(y:0)y=0++ f, H(y:0)y=0++ f, H(y:0)y=32++ f REP8   #0 0
  vr80(v_mulmd, Hy0, 0, INC, Hy0, 0, INC, Hy0, 32, INC, REP8);
  // vrmulmd H(y:16)y=0++ f, H(y:16)y=0++ f, H(y:16)y=32++ f REP8   #0 0
  vr80(v_mulmd, Hy16, 0, INC, Hy16, 0, INC, Hy16, 32, INC, REP8);
  // vradd HX(y:0)y=0++ f, HX(y:0)y=0++ f, HX(y:0)y=16++ f REP8   #0 0
  vr80(v_add, HXy0, 0, INC, HXy0, 0, INC, HXy0, 16, INC, REP8);
  //vst HX(y:0)y=0++ f, 0(r0+=r5) REP8 ; x=1 D=380 y=7 z=0
  vst80(W16, HXy0, 0, INC, 0, r0, r5, REP8);

  adds8(r0, r5);
  adds8(r1, r5);
  adds8(r2, r5);
  adds8(r3, r5);
  // blt
  bc_rd_rs_o(c_lt, r0, r4, loop1);
  rts();


  END
