/* Start of Autogenerated Code */
/* Autogenerated from what? I am gonna edit it anyway... */

enum table_c {
  c_eq, c_ne, c_cs, c_lo = c_cs, c_cc, c_hs = c_cc, c_mi, c_pl, c_vs, c_vc, c_hi, c_ls, c_ge, c_lt, c_gt, c_le, c_, c_f
};
enum table_f {
  f_fadd, f_fsub, f_fmul, f_fdiv, f_fcmp, f_fabs, f_frsb, f_fmax, f_frcp, f_frsqrt, f_fnmul, f_fmin, f_fld1, f_fld0, f_fop14, f_fop15
};
enum table_p {
  p_mov, p_cmn, p_add, p_bic, p_mul, p_eor, p_sub, p_and, p_mvn, p_ror, p_cmp, p_rsb, p_btst, p_or, p_extu, p_max, p_bset, p_min, p_bclr, p_adds2, p_bchg, p_adds4, p_adds8, p_adds16, p_exts, p_neg, p_lsr, p_clz, p_lsl, p_brev, p_asr, p_abs
};
enum table_q {
  q_mov, q_add, q_mul, q_sub, q_mvn, q_cmp, q_btst, q_extu, q_bset, q_bclr, q_bchg, q_adds8, q_exts, q_lsr, q_lsl, q_asr
};
enum table_w {
  w_, w_h, w_b, w_sh
};

// vector operations
enum table_v {
 v_mov,        v_mask,        v_cmbod,       v_cmbev,       v_altl,        v_altu,        v_brev,        v_ror,
 v_lsl,        v_asl,         v_lsr,         v_asr,         v_op12,        v_op13,        v_op14,        v_op15,
 v_and,        v_or,          v_eor,         v_andn,        v_popcnt,      v_log2,        v_op22,        v_op23,
 v_min,        v_max,         v_dist,        v_distq,       v_minq,        v_sgn,         v_clamp,       v_cmpge,
 v_add,        v_adds,        v_addc,        v_addsc,       v_sub,         v_subs,        v_subc,        v_subsc,
 v_rsub,       v_rsubs,       v_rsubc,       v_rsubsc,      v_op44,        v_op45,        v_op46,        v_op47,
 v_mul,        v_muls,        v_mulmd,       v_mulmds,      v_mulhd_ss,     v_mulhd_su,   v_mulhd_us,    v_mulhd_uu,
 v_mulhdr_ss,  v_mulhdr_su,   v_mulhdr_us,   v_mulhdr_uu,   v_op60,        v_op61,        v_op62,        v_op63
};

// vector condition codes
enum table_vc {
vc_all, vc_none, vc_ifz, vc_ifnz, vc_ifn, vc_ifnn, vc_ifc, vc_ifnc
};

// Scalar register update funcs
// not everything evaluated, partially placeholders
enum table_sru {
sru_sumu, sru_sum, sru_max1, sru_imin, sru_max2, sru_imax, sru_max3, sru_max4
};

// ; halt?
// 0000 0000 0000 0000
#define halt() emit1(0x0000)

// ; nop
// 0000 0000 0000 0001
#define nop() emit1(0x0001)

// ; unk1 0x%02x{x}
// 0000 0000 0000 001x
#define unk1_x(x) emit1(0x0002|((x)&0x1))

// ; unk2 0x%02x{x}
// 0000 0000 0000 01xx
#define unk2_x(x) emit1(0x0004|((x)&0x3))

// ; rti
// 0000 0000 0000 1010
#define rti() emit1(0x000a)

// ; unk3 0x%02x{x}
// 0000 0000 0000 1xxx
#define unk3_x(x) emit1(0x0008|((x)&0x7))

// ; unk4 0x%02x{x}
// 0000 0000 0001 xxxx
#define unk4_x(x) emit1(0x0010|((x)&0xf))

// ; unk5 0x%02x{x}
// 0000 0000 001x xxxx
#define unk5_x(x) emit1(0x0020|((x)&0x1f))

// ; rts
// 0000 0000 0101 1010
#define rts() emit1(0x005a)

// ; b r%i{d}
// 0000 0000 010d dddd
#define b_rd(d) emit1(0x0040|((d)&0x1f))

// ; bl r%i{d}
// 0000 0000 011d dddd
#define bl_rd(d) emit1(0x0060|((d)&0x1f))

// ; tbb r%i{d}
// 0000 0000 100d dddd
#define tbb_rd(d) emit1(0x0080|((d)&0x1f))

// ; tbh r%i{d}
// 0000 0000 101d dddd
#define tbh_rd(d) emit1(0x00a0|((d)&0x1f))

// ; mov r%i{d}, cpuid
// 0000 0000 111d dddd
#define mov_rd_cpuid(d) emit1(0x00e0|((d)&0x1f))

// ; unk7 0x%02x{x}
// 0000 0000 1xxx xxxx
#define unk7_x(x) emit1(0x0080|((x)&0x7f))

// ; unk8 0x%02x{x}
// 0000 0001 xxxx xxxx
#define unk8_x(x) emit1(0x0100|((x)&0xff))

// ; push r6
// 0000 0010 1010 0000
#define push_r6() emit1(0x02a0)

// ; pop  r6
// 0000 0010 0010 0000
#define pop_r6() emit1(0x0220)

// ; push r6, lr
// 0000 0011 1010 0000
#define push_r6_lr() emit1(0x03a0)

// ; pop  r6, pc
// 0000 0011 0010 0000
#define pop_r6_pc() emit1(0x0320)

// ; push r%d{b*8}
// 0000 0010 1bb0 0000
#define push_rb(b) emit1(0x0280|(((b)<<5)&0x60))

// ; pop  r%d{b*8}
// 0000 0010 0bb0 0000
#define pop_rb(b) emit1(0x0200|(((b)<<5)&0x60))

// ; push r%d{b*8}, lr
// 0000 0011 1bb0 0000
#define push_rb_lr(b) emit1(0x0380|(((b)<<5)&0x60))

// ; pop  r%d{b*8}, pc
// 0000 0011 0bb0 0000
#define pop_rb_pc(b) emit1(0x0300|(((b)<<5)&0x60))

// ; push r6-r%d{6+n}
// 0000 0010 101n nnnn
#define push_r6_rn(n) emit1(0x02a0|((n)&0x1f))

// ; pop  r6-r%d{6+n}
// 0000 0010 001n nnnn
#define pop_r6_rn(n) emit1(0x0220|((n)&0x1f))

// ; push r6-r%d{6+n}, lr
// 0000 0011 101n nnnn
#define push_r6_rn_lr(n) emit1(0x03a0|((n)&0x1f))

// ; pop  r6-r%d{6+n}, pc
// 0000 0011 001n nnnn
#define pop_r6_rn_pc(n) emit1(0x0320|((n)&0x1f))

// ; push r%d{b*8}-r%d{(n+b*8)&31}
// 0000 0010 1bbn nnnn
#define push_rb_rnb(b, n) emit1(0x0280|(((b)<<5)&0x60)|((n)&0x1f))

// ; pop  r%d{b*8}-r%d{(n+b*8)&31}
// 0000 0010 0bbn nnnn
#define pop_rb_rnb(b, n) emit1(0x0200|(((b)<<5)&0x60)|((n)&0x1f))

// ; push r%d{b*8}-r%d{(n+b*8)&31}, lr
// 0000 0011 1bbn nnnn
#define push_rb_rnb_lr(b, n) emit1(0x0380|(((b)<<5)&0x60)|((n)&0x1f))

// ; pop  r%d{b*8}-r%d{(n+b*8)&31}, pc
// 0000 0011 0bbn nnnn
#define pop_rb_rnb_pc(b, n) emit1(0x0300|(((b)<<5)&0x60)|((n)&0x1f))

// ; ld r%i{d}, 0x%02x{o*4}(sp)
// 0000 010o oooo dddd
#define ld_rd_o5_sp(d, o) emit1(0x0400|(((o)<<4)&0x1f0)|((d)&0xf))

// ; st r%i{d}, 0x%02x{o*4}(sp)
// 0000 011o oooo dddd
#define st_rd_o5_sp(d, o) emit1(0x0600|(((o)<<4)&0x1f0)|((d)&0xf))

// ; ld%s{w} r%i{d}, (r%i{s})
// 0000 1ww0 ssss dddd
#define ld_w_rd_rs(w, d, s) emit1(0x0800|(((w)<<9)&0x600)|(((s)<<4)&0xf0)|((d)&0xf))

// ; st%s{w} r%i{d}, (r%i{s})
// 0000 1ww1 ssss dddd
#define st_w_rd_rs(w, d, s) emit1(0x0900|(((w)<<9)&0x600)|(((s)<<4)&0xf0)|((d)&0xf))

// ; add sp, #0x%x{o*4}
// 0001 0ooo ooo1 1001
#define add_sp_o6(o) emit1(0x1019|(((o)<<5)&0x7e0))

// ; lea r%i{d}, 0x%x{o*4}(sp)
// 0001 0ooo oood dddd
#define lea_rd_o6_sp(d, o) emit1(0x1000|(((o)<<5)&0x7e0)|((d)&0x1f))

// ; b%s{c} 0x%08x{$+o*2}
// 0001 1ccc cooo oooo
#define bc_o7(c, o) emit1(0x1800|(((c)<<7)&0x780)|((o)&0x7f))

// ; ld  r%i{d}, 0x%02x{u*4}(r%i{s})
// 0010 uuuu ssss dddd
#define ld_rd_u_rs(d, u, s) emit1(0x2000|(((u)<<8)&0xf00)|(((s)<<4)&0xf0)|((d)&0xf))

// ; st  r%i{d}, 0x%02x{u*4}(r%i{s})
// 0011 uuuu ssss dddd
#define st_rd_u_rs(d, u, s) emit1(0x3000|(((u)<<8)&0xf00)|(((s)<<4)&0xf0)|((d)&0xf))

// ; %s{p} r%i{d}, r%i{s}
// 010p pppp ssss dddd
#define p_rd_rs(p, d, s) emit1(0x4000|(((p)<<8)&0x1f00)|(((s)<<4)&0xf0)|((d)&0xf))

// ; add r%i{d}, r%i{s} shl #%i{x}
// 0101 0xxs ssss dddd
#define add_rd_rs_shl_x(d, s, x) emit1(0x5000|(((x)<<9)&0x600)|(((s)<<4)&0x1f0)|((d)&0xf))

// ; %s{q} r%i{d}, #%i{u}
// 011q qqqu uuuu dddd
#define q_rd_u(q, d, u) emit1(0x6000|(((q)<<9)&0x1e00)|(((u)<<4)&0x1f0)|((d)&0xf))

// ; b%s{c} r%i{d}, r%i{s}, 0x%08x{$+o*2}
// 1000 cccc 0000 dddd 01ss ssoo oooo oooo
#define bc_rd_rs_o10(c, d, s, o) emit2(0x8000|(((c)<<8)&0xf00)|((d)&0xf), 0x4000|(((s)<<10)&0x3c00)|((o)&0x3ff))

// ; b%s{c} r%i{d}, #%i{u}, 0x%08x{$+o*2}
// 1000 cccc 0000 dddd 11uu uuuu oooo oooo
#define bc_rd_u_o8(c, d, u, o) emit2(0x8000|(((c)<<8)&0xf00)|((d)&0xf), 0xc000|(((u)<<8)&0x3f00)|((o)&0xff))

// ; addcmpb%s{c} r%i{d}, r%i{a}, r%i{s}, 0x%08x{$+o*2}
// 1000 cccc aaaa dddd 00ss ssoo oooo oooo
#define addcmpb_c_rd_ra_rs_o10(c, d, a, s, o) emit2(0x8000|(((c)<<8)&0xf00)|(((a)<<4)&0xf0)|((d)&0xf), 0x0000|(((s)<<10)&0x3c00)|((o)&0x3ff))

// ; addcmpb%s{c} r%i{d}, #%i{i}, r%i{s}, 0x%08x{$+o*2}
// 1000 cccc iiii dddd 01ss ssoo oooo oooo
#define addcmpb_c_rd_i_rs_o10(c, d, i, s, o) emit2(0x8000|(((c)<<8)&0xf00)|(((i)<<4)&0xf0)|((d)&0xf), 0x4000|(((s)<<10)&0x3c00)|((o)&0x3ff))

// ; addcmpb%s{c} r%i{d}, r%i{a}, #%i{u}, 0x%08x{$+o*2}
// 1000 cccc aaaa dddd 10uu uuuu oooo oooo
#define addcmpb_c_rd_ra_u_o8(c, d, a, u, o) emit2(0x8000|(((c)<<8)&0xf00)|(((a)<<4)&0xf0)|((d)&0xf), 0x8000|(((u)<<8)&0x3f00)|((o)&0xff))

// ; addcmpb%s{c} r%i{d}, #%i{i}, #%i{u}, 0x%08x{$+o*2}
// 1000 cccc iiii dddd 11uu uuuu oooo oooo
#define addcmpb_c_rd_i_u_o8(c, d, i, u, o) emit2(0x8000|(((c)<<8)&0xf00)|(((i)<<4)&0xf0)|((d)&0xf), 0xc000|(((u)<<8)&0x3f00)|((o)&0xff))

// ; b%s{c} 0x%08x{$+o*2}
// 1001 cccc 0ooo oooo oooo oooo oooo oooo
#define bc_o23(c, o) emit2(0x9000|(((c)<<8)&0xf00)|(((o)>>16)&0x7f), 0x0000|((o)&0xffff))

// ; bl  0x%08x{$+o*2}
// 1001 oooo 1ooo oooo oooo oooo oooo oooo
#define bl_o27(o) emit2(0x9080|((((o)>>23)<<8)&0xf00)|(((o)>>16)&0x7f), 0x0000|((o)&0xffff))

// ; ld%s{w}%s{c} r%i{d}, (r%i{a}, r%i{b})
// 1010 0000 ww0d dddd aaaa accc c00b bbbb
#define ld_w_c_rd_ra_rb(w, c, d, a, b) emit2(0xa000|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; st%s{w}%s{c} r%i{d}, (r%i{a}, r%i{b})
// 1010 0000 ww1d dddd aaaa accc c00b bbbb
#define st_w_c_rd_ra_rb(w, c, d, a, b) emit2(0xa020|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; ld%s{w}%s{c} r%i{d}, 0x%x{u}(r%i{a})
// 1010 0000 ww0d dddd aaaa accc c10u uuuu
#define ld_w_c_rd_u_ra(w, c, d, u, a) emit2(0xa000|(((w)<<6)&0xc0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; st%s{w}%s{c} r%i{d}, 0x%x{u}(r%i{a})
// 1010 0000 ww1d dddd aaaa accc c10u uuuu
#define st_w_c_rd_u_ra(w, c, d, u, a) emit2(0xa020|(((w)<<6)&0xc0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; bad ld/st with (ra, rb) or (ra, #u)
// 1010 0000 wwxd dddd aaaa accc cxxu uuuu
#define bad_ld_st_with_ra_rb_or_ra_u() emit2(0xa000|(((w)<<6)&0xc0)|((((x)>>2)<<5)&0x20)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|(((x)<<5)&0x60)|((u)&0x1f))

// ; ld%s{w}%s{c} r%i{d}, --(r%i{s})
// 1010 0100 ww0d dddd ssss sccc c000 0000
#define ld_w_c_rd_dec_rs(w, c, d, s) emit2(0xa400|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((c)<<7)&0x780))

// ; st%s{w}%s{c} r%i{d}, --(r%i{s})
// 1010 0100 ww1d dddd ssss sccc c000 0000
#define st_w_c_rd_dec_rs(w, c, d, s) emit2(0xa420|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((c)<<7)&0x780))

// ; ld%s{w}%s{c} r%i{d}, (r%i{s})++
// 1010 0101 ww0d dddd ssss sccc c000 0000
#define ld_w_c_rd_rs_inc(w, c, d, s) emit2(0xa500|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((c)<<7)&0x780))

// ; st%s{w}%s{c} r%i{d}, (r%i{s})++
// 1010 0101 ww1d dddd ssss sccc c000 0000
#define st_w_c_rd_rs_inc(w, c, d, s) emit2(0xa520|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((c)<<7)&0x780))

// ; bad ld/st with pre-decrement/post-increment addressing
// 1010 010x wwxd dddd ssss sccc cxxx xxxx
#define bad_ld_st_with_pre_decrement_post_increment_addressing() emit2(0xa400|((((x)>>8)<<8)&0x100)|(((w)<<6)&0xc0)|((((x)>>7)<<5)&0x20)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((c)<<7)&0x780)|((x)&0x7f))

// ; ld%s{w} r%i{d}, 0x%x{o}(r%i{s})
// 1010 001o ww0d dddd ssss sooo oooo oooo
#define ld_w_rd_o12_rs(w, d, o, s) emit2(0xa200|((((o)>>11)<<8)&0x100)|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|((o)&0x7ff))

// ; st%s{w} r%i{d}, 0x%x{o}(r%i{s})
// 1010 001o ww1d dddd ssss sooo oooo oooo
#define st_w_rd_o12_rs(w, d, o, s) emit2(0xa220|((((o)>>11)<<8)&0x100)|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|((o)&0x7ff))

// ; ld%s{w} r%i{d}, 0x%x{o}(r%i{s}) x=%d{x}?
// 1010 0x1o ww0d dddd ssss sooo oooo oooo
#define ld_w_rd_o12_rs_xx(w, d, o, s, x) emit2(0xa200|(((x)<<10)&0x400)|((((o)>>11)<<8)&0x100)|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|((o)&0x7ff))

// ; st%s{w} r%i{d}, 0x%x{o}(r%i{s}) x=%d{x}?
// 1010 0x1o ww1d dddd ssss sooo oooo oooo
#define st_w_rd_o12_rs_xx(w, d, o, s, x) emit2(0xa220|(((x)<<10)&0x400)|((((o)>>11)<<8)&0x100)|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|((o)&0x7ff))

// ; ld%s{w} r%i{d}, 0x%0x{o}(r24)
// 1010 1000 ww0d dddd oooo oooo oooo oooo
#define ld_w_rd_o16_r24(w, d, o) emit2(0xa800|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; st%s{w} r%i{d}, 0x%0x{o}(r24)
// 1010 1000 ww1d dddd oooo oooo oooo oooo
#define st_w_rd_o16_r24(w, d, o) emit2(0xa820|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; ld%s{w} r%i{d}, 0x%0x{o}(sp)
// 1010 1001 ww0d dddd oooo oooo oooo oooo
#define ld_w_rd_o16_sp(w, d, o) emit2(0xa900|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; st%s{w} r%i{d}, 0x%0x{o}(sp)
// 1010 1001 ww1d dddd oooo oooo oooo oooo
#define st_w_rd_o16_sp(w, d, o) emit2(0xa920|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; ld%s{w} r%i{d}, 0x%0x{o}(pc)
// 1010 1010 ww0d dddd oooo oooo oooo oooo
#define ld_w_rd_o16_pc(w, d, o) emit2(0xaa00|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; st%s{w} r%i{d}, 0x%0x{o}(pc)
// 1010 1010 ww1d dddd oooo oooo oooo oooo
#define st_w_rd_o16_pc(w, d, o) emit2(0xaa20|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; ld%s{w} r%i{d}, 0x%x{o}(r0)
// 1010 1011 ww0d dddd oooo oooo oooo oooo
#define ld_w_rd_o16_r0(w, d, o) emit2(0xab00|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; st%s{w} r%i{d}, 0x%x{o}(r0)
// 1010 1011 ww1d dddd oooo oooo oooo oooo
#define st_w_rd_o16_r0(w, d, o) emit2(0xab20|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; ld%s{w} r%i{d}, 0x%x{o}(?? %i{x})
// 1010 11xx ww0d dddd oooo oooo oooo oooo
#define ld_w_rd_o16_x(w, d, o, x) emit2(0xac00|(((x)<<8)&0x300)|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; st%s{w} r%i{d}, 0x%x{o}(?? %i{x})
// 1010 11xx ww1d dddd oooo oooo oooo oooo
#define st_w_rd_o16_x(w, d, o, x) emit2(0xac20|(((x)<<8)&0x300)|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|((o)&0xffff))

// ; mulhd.ss %s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 0100 000d dddd aaaa accc c00b bbbb
#define mulhd_ss_c_rd_ra_rb(c, d, a, b) emit2(0xc400|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; mulhd.su %s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 0100 001d dddd aaaa accc c00b bbbb
#define mulhd_su_c_rd_ra_rb(c, d, a, b) emit2(0xc420|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; mulhd.us %s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 0100 010d dddd aaaa accc c00b bbbb
#define mulhd_us_c_rd_ra_rb(c, d, a, b) emit2(0xc440|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; mulhd.uu %s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 0100 011d dddd aaaa accc c00b bbbb
#define mulhd_uu_c_rd_ra_rb(c, d, a, b) emit2(0xc460|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; mulhd.ss %s{c} r%i{d}, r%i{a}, #%d{u}
// 1100 0100 000d dddd aaaa accc c10u uuuu
#define mulhd_ss_c_rd_ra_u(c, d, a, u) emit2(0xc400|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; mulhd.su %s{c} r%i{d}, r%i{a}, #%d{u}
// 1100 0100 001d dddd aaaa accc c10u uuuu
#define mulhd_su_c_rd_ra_u(c, d, a, u) emit2(0xc420|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; mulhd.us %s{c} r%i{d}, r%i{a}, #%d{u}
// 1100 0100 010d dddd aaaa accc c10u uuuu
#define mulhd_us_c_rd_ra_u(c, d, a, u) emit2(0xc440|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; mulhd.uu %s{c} r%i{d}, r%i{a}, #%d{u}
// 1100 0100 011d dddd aaaa accc c10u uuuu
#define mulhd_uu_c_rd_ra_u(c, d, a, u) emit2(0xc460|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; divs%s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 0100 100d dddd aaaa accc c00b bbbb
#define divs_c_rd_ra_rb(c, d, a, b) emit2(0xc480|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; divsu%s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 0100 101d dddd aaaa accc c00b bbbb
#define divsu_c_rd_ra_rb(c, d, a, b) emit2(0xc4a0|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; divus%s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 0100 110d dddd aaaa accc c00b bbbb
#define divus_c_rd_ra_rb(c, d, a, b) emit2(0xc4c0|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; divu%s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 0100 111d dddd aaaa accc c00b bbbb
#define divu_c_rd_ra_rb(c, d, a, b) emit2(0xc4e0|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; divs%s{c} r%i{d}, r%i{a}, #%d{u}
// 1100 0100 100d dddd aaaa accc c10u uuuu
#define divs_c_rd_ra_u(c, d, a, u) emit2(0xc480|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; divsu%s{c} r%i{d}, r%i{a}, #%d{u}
// 1100 0100 101d dddd aaaa accc c10u uuuu
#define divsu_c_rd_ra_u(c, d, a, u) emit2(0xc4a0|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; divus%s{c} r%i{d}, r%i{a}, #%d{u}
// 1100 0100 110d dddd aaaa accc c10u uuuu
#define divus_c_rd_ra_u(c, d, a, u) emit2(0xc4c0|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; divu%s{c} r%i{d}, r%i{a}, #%d{u}
// 1100 0100 111d dddd aaaa accc c10u uuuu
#define divu_c_rd_ra_u(c, d, a, u) emit2(0xc4e0|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; add%s{c} r%d{d}, r%d{a}, r%d{b} shl 8
// 1100 0101 111d dddd aaaa accc c00b bbbb
#define add_c_rd_ra_rb_shl(c, d, a, b) emit2(0xc5e0|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; test5 add%s{c} r%i{d}, r%i{a}, r%i{b} shl %d{x+1}
// 1100 0101 xxxd dddd aaaa accc c00b bbbb
#define test5_add_c_rd_ra_rb_shl_x(c, d, a, b, x) emit2(0xc500|(((x)<<5)&0xe0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; test5 add%s{c} r%i{d}, r%i{a}, #%d{u} shl %d{x+1}
// 1100 0101 xxxd dddd aaaa accc c10u uuuu
#define test5_add_c_rd_ra_u_shl_x(c, d, a, u, x) emit2(0xc500|(((x)<<5)&0xe0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; test6 add%s{c} r%i{d}, r%i{a}, r%i{b} lsr %d{x+1}
// 1100 0110 xxxd dddd aaaa accc c00b bbbb
#define test6_add_c_rd_ra_rb_lsr_x(c, d, a, b, x) emit2(0xc600|(((x)<<5)&0xe0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; test6 add%s{c} r%i{d}, r%i{a}, #%d{u} lsr %d{x+1}
// 1100 0110 xxxd dddd aaaa accc c10u uuuu
#define test6_add_c_rd_ra_u_lsr_x(c, d, a, u, x) emit2(0xc600|(((x)<<5)&0xe0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; test6 s%s{c} r%i{d}, r%i{a}, r%i{b} ;%d{x}
// 1100 0110 xxxd dddd aaaa accc c00b bbbb
#define test6_sc_rd_ra_rb_x(c, d, a, b, x) emit2(0xc600|(((x)<<5)&0xe0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; test6 u%s{c} r%i{d}, r%i{a}, r%i{b} ;%d{x}
// 1100 0110 xxxd dddd aaaa accc c00b bbbb
#define test6_uc_rd_ra_rb_x(c, d, a, b, x) emit2(0xc600|(((x)<<5)&0xe0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; test6 s%s{c} r%i{d}, r%i{a}, #%d{u} ;%d{x}
// 1100 0110 xxxd dddd aaaa accc c10u uuuu
#define test6_sc_rd_ra_u_x(c, d, a, u, x) emit2(0xc600|(((x)<<5)&0xe0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; test6 u%s{c} r%i{d}, r%i{a}, #%d{u} ;%d{x}
// 1100 0110 xxxd dddd aaaa accc c10u uuuu
#define test6_uc_rd_ra_u_x(c, d, a, u, x) emit2(0xc600|(((x)<<5)&0xe0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; test7 s%s{c} r%i{d}, r%i{a}, r%i{b} ;%d{x}
// 1100 0111 xxxd dddd aaaa accc c00b bbbb
#define test7_sc_rd_ra_rb_x(c, d, a, b, x) emit2(0xc700|(((x)<<5)&0xe0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; test7 u%s{c} r%i{d}, r%i{a}, r%i{b} ;%d{x}
// 1100 0111 xxxd dddd aaaa accc c00b bbbb
#define test7_uc_rd_ra_rb_x(c, d, a, b, x) emit2(0xc700|(((x)<<5)&0xe0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; test7 s%s{c} r%i{d}, r%i{a}, #%d{u} ;%d{x}
// 1100 0111 xxxd dddd aaaa accc c10u uuuu
#define test7_sc_rd_ra_u_x(c, d, a, u, x) emit2(0xc700|(((x)<<5)&0xe0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; test7 u%s{c} r%i{d}, r%i{a}, #%d{u} ;%d{x}
// 1100 0111 xxxd dddd aaaa accc c10u uuuu
#define test7_uc_rd_ra_u_x(c, d, a, u, x) emit2(0xc700|(((x)<<5)&0xe0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((u)&0x1f))

// ; %s{p}%s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 00pp pppd dddd aaaa accc c00b bbbb
#define p_c_rd_ra_rb(p, c, d, a, b) emit2(0xc000|(((p)<<5)&0x3e0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; %s{p}%s{c} r%i{d}, r%i{a}, #%i{i}
// 1100 00pp pppd dddd aaaa accc c1ii iiii
#define p_c_rd_ra_i(p, c, d, a, i) emit2(0xc000|(((p)<<5)&0x3e0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((i)&0x3f))

// ; %s{f}%s{c} r%i{d}, r%i{a}, r%i{b}
// 1100 100f fffd dddd aaaa accc c00b bbbb
#define f_c_rd_ra_rb(f, c, d, a, b) emit2(0xc800|(((f)<<5)&0x1e0)|((d)&0x1f), 0x0000|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((b)&0x1f))

// ; %s{f}%s{c} r%i{d}, r%i{a}, #%i{i}
// 1100 100f fffd dddd aaaa accc c1ii iiii
#define f_c_rd_ra_i(f, c, d, a, i) emit2(0xc800|(((f)<<5)&0x1e0)|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((i)&0x3f))

// ; ftrunc r%i{d}, r%i{a} ; convert to int
// 1100 1010 000d dddd aaaa accc c100 0000
#define ftrunc_rd_ra_convert_to_int(d, a) emit2(0xca00|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780))

// ; floor r%i{d}, r%i{a} ; convert to int
// 1100 1010 001d dddd aaaa accc c100 0000
#define floor_rd_ra_convert_to_int(d, a) emit2(0xca20|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780))

// ; flts r%i{d}, r%i{a} ; convert to float from signed integer
// 1100 1010 010d dddd aaaa accc c100 0000
#define flts_rd_ra_convert_to_float_from_signed_integer(d, a) emit2(0xca40|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780))

// ; fltu r%i{d}, r%i{a} ; convert to float from unsigned integer
// 1100 1010 011d dddd aaaa accc c100 0000
#define fltu_rd_ra_convert_to_float_from_unsigned_integer(d, a) emit2(0xca60|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780))

// ; ftrunc r%i{d}, r%i{a}, #%i{i} ; unexpected const
// 1100 1010 000d dddd aaaa accc c1ii iiii
#define ftrunc_rd_ra_i_unexpected_const(d, a, i) emit2(0xca00|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((i)&0x3f))

// ; floor r%i{d}, r%i{a}, #%i{i} ; unexpected const
// 1100 1010 001d dddd aaaa accc c1ii iiii
#define floor_rd_ra_i_unexpected_const(d, a, i) emit2(0xca20|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((i)&0x3f))

// ; flts r%i{d}, r%i{a}, #%i{i} ; unexpected const
// 1100 1010 010d dddd aaaa accc c1ii iiii
#define flts_rd_ra_i_unexpected_const(d, a, i) emit2(0xca40|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((i)&0x3f))

// ; fltu r%i{d}, r%i{a}, #%i{i} ; unexpected const
// 1100 1010 011d dddd aaaa accc c1ii iiii
#define fltu_rd_ra_i_unexpected_const(d, a, i) emit2(0xca60|((d)&0x1f), 0x0040|(((a)<<11)&0xf800)|(((c)<<7)&0x780)|((i)&0x3f))

// ; test3 mov r%d{d}, reg%d{a}
// 1100 1100 001d dddd 0000 0000 000a aaaa
#define test3_mov_rd_reg_a(d, a) emit2(0xcc20|((d)&0x1f), 0x0000|((a)&0x1f))

// ; test3 mov reg%d{a}, r%d{d}
// 1100 1100 000a aaaa 0000 0000 000d dddd
#define test3_mov_reg_a_rd(a, d) emit2(0xcc00|((a)&0x1f), 0x0000|((d)&0x1f))

// ; test3 mov r%d{d}, reg%d{a} %x{x}?
// 1100 1100 xxxa aaaa 0000 0000 000d dddd
#define test3_mov_rd_reg_a_x(d, a, x) emit2(0xcc00|(((x)<<5)&0xe0)|((a)&0x1f), 0x0000|((d)&0x1f))

// ; %s{p} r%i{d}, #0x%04x{i}
// 1011 00pp pppd dddd iiii iiii iiii iiii
#define p_rd_i(p, d, i) emit2(0xb000|(((p)<<5)&0x3e0)|((d)&0x1f), 0x0000|((i)&0xffff))

// ; lea r%i{d}, 0x%04x{i}(r%i{s})
// 1011 01ss sssd dddd iiii iiii iiii iiii
#define lea_rd_i_rs(d, i, s) emit2(0xb400|(((s)<<5)&0x3e0)|((d)&0x1f), 0x0000|((i)&0xffff))

// ; lea r%i{d}, 0x%08x{$+o} ;pc
// 1011 1111 111d dddd oooo oooo oooo oooo
#define lea_rd_o16_pc(d, o) emit2(0xbfe0|((d)&0x1f), 0x0000|((o)&0xffff))

// ; op0
// 1110 0000 ssss dddd uuuu uuuu uuuu uuuu uuuu uuuu uuuu uuuu
#define op0() emit3(0xe000|(((s)<<4)&0xf0)|((d)&0xf), 0x0000|(((u)>>16)&0xffff), 0x0000|((u)&0xffff))

// ; op1
// 1110 0001 ssss dddd uuuu uuuu uuuu uuuu uuuu uuuu uuuu uuuu
#define op1() emit3(0xe100|(((s)<<4)&0xf0)|((d)&0xf), 0x0000|(((u)>>16)&0xffff), 0x0000|((u)&0xffff))

// ; op2
// 1110 0010 ssss dddd uuuu uuuu uuuu uuuu uuuu uuuu uuuu uuuu
#define op2() emit3(0xe200|(((s)<<4)&0xf0)|((d)&0xf), 0x0000|(((u)>>16)&0xffff), 0x0000|((u)&0xffff))

// ; op3
// 1110 0011 ssss dddd uuuu uuuu uuuu uuuu uuuu uuuu uuuu uuuu
#define op3() emit3(0xe300|(((s)<<4)&0xf0)|((d)&0xf), 0x0000|(((u)>>16)&0xffff), 0x0000|((u)&0xffff))

// ; op4
// 1110 0100 ssss dddd uuuu uuuu uuuu uuuu uuuu uuuu uuuu uuuu
#define op4() emit3(0xe400|(((s)<<4)&0xf0)|((d)&0xf), 0x0000|(((u)>>16)&0xffff), 0x0000|((u)&0xffff))

// ; lea r%i{d}, 0x%08x{$+o} ;(pc)
// 1110 0101 000d dddd oooo oooo oooo oooo oooo oooo oooo oooo
#define lea_rd_o32_pc(d, o) emit3(0xe500|((d)&0x1f), 0x0000|(((o)>>16)&0xffff), 0x0000|((o)&0xffff))

// ; lea r%i{d}, 0x%08x{$+o} ;(pc) ; %x{x}?
// 1110 0101 xxxd dddd oooo oooo oooo oooo oooo oooo oooo oooo
#define lea_rd_o32_pc_x(d, o, x) emit3(0xe500|(((x)<<5)&0xe0)|((d)&0x1f), 0x0000|(((o)>>16)&0xffff), 0x0000|((o)&0xffff))

// ; ld%s{w} r%i{d}, 0x%08x{o}(r%i{s})
// 1110 0110 ww0d dddd ssss sooo oooo oooo oooo oooo oooo oooo
#define ld_w_rd_o27_rs(w, d, o, s) emit3(0xe600|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((o)>>16)&0x7ff), 0x0000|((o)&0xffff))

// ; st%s{w} r%i{d}, 0x%08x{o}(r%i{s})
// 1110 0110 ww1d dddd ssss sooo oooo oooo oooo oooo oooo oooo
#define st_w_rd_o27_rs(w, d, o, s) emit3(0xe620|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((o)>>16)&0x7ff), 0x0000|((o)&0xffff))

// ; ld%s{w} r%i{d}, 0x%08x{$+o} ;(pc)
// 1110 0111 ww0d dddd 1111 1ooo oooo oooo oooo oooo oooo oooo
#define ld_w_rd_o27_pc(w, d, o) emit3(0xe700|(((w)<<6)&0xc0)|((d)&0x1f), 0xf800|(((o)>>16)&0x7ff), 0x0000|((o)&0xffff))

// ; st%s{w} r%i{d}, 0x%08x{$+o} ;(pc)
// 1110 0111 ww1d dddd 1111 1ooo oooo oooo oooo oooo oooo oooo
#define st_w_rd_o27_pc(w, d, o) emit3(0xe720|(((w)<<6)&0xc0)|((d)&0x1f), 0xf800|(((o)>>16)&0x7ff), 0x0000|((o)&0xffff))

// ; test ld%s{w} r%i{d}, 0x%08x{o}(r%i{s})
// 1110 0111 ww0d dddd ssss sooo oooo oooo oooo oooo oooo oooo
#define test_ld_w_rd_o27_rs(w, d, o, s) emit3(0xe700|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((o)>>16)&0x7ff), 0x0000|((o)&0xffff))

// ; test st%s{w} r%i{d}, 0x%08x{o}(r%i{s})
// 1110 0111 ww1d dddd ssss sooo oooo oooo oooo oooo oooo oooo
#define test_st_w_rd_o27_rs(w, d, o, s) emit3(0xe720|(((w)<<6)&0xc0)|((d)&0x1f), 0x0000|(((s)<<11)&0xf800)|(((o)>>16)&0x7ff), 0x0000|((o)&0xffff))

// ; %s{p} r%i{d}, #0x%08x{u}
// 1110 10pp pppd dddd uuuu uuuu uuuu uuuu uuuu uuuu uuuu uuuu
#define p_rd_u(p, d, u) emit3(0xe800|(((p)<<5)&0x3e0)|((d)&0x1f), 0x0000|(((u)>>16)&0xffff), 0x0000|((u)&0xffff))

// ; add r%i{d}, r%i{s}, #0x%08x{u}
// 1110 11ss sssd dddd uuuu uuuu uuuu uuuu uuuu uuuu uuuu uuuu
#define add_rd_rs_u(d, s, u) emit3(0xec00|(((s)<<5)&0x3e0)|((d)&0x1f), 0x0000|(((u)>>16)&0xffff), 0x0000|((u)&0xffff))

// ; vldb %x{y}?, (r%i{a}), %x{x}
// 1111 0000 0000 yyyy  0000 0011 1000 aaaa  xxxx xxxx xxxx xxxx
#define vldb_y_ra_x(y, a, x) emit3(0xf000|((y)&0xf), 0x0380|((a)&0xf), 0x0000|((x)&0xffff))

// ; vstb %x{y}?, (r%i{a}), %x{x}
// 1111 0000 1000 yyyy  0000 0011 1000 aaaa  xxxx xxxx xxxx xxxx
#define vstb_y_ra_x(y, a, x) emit3(0xf080|((y)&0xf), 0x0380|((a)&0xf), 0x0000|((x)&0xffff))

// ; vldh %x{y}?, (r%i{a}), %x{x}
// 1111 1000 0000 yyyy  0000 0011 1000 aaaa  xxxx xxxx xxxx xxxx
#define vldh_y_ra_x(y, a, x) emit3(0xf800|((y)&0xf), 0x0380|((a)&0xf), 0x0000|((x)&0xffff))

// ; vsth %x{y}?, (r%i{a}), %x{x}
// 1111 1000 1000 yyyy  0000 0011 1000 aaaa  xxxx xxxx xxxx xxxx
#define vsth_y_ra_x(y, a, x) emit3(0xf880|((y)&0xf), 0x0380|((a)&0xf), 0x0000|((x)&0xffff))

// ; vector80 0x%x{x}, 0x%x{y}, 0x%x{z}
// 1111 1xxx xxxx xxxx yyyy yyyy yyyy yyyy yyyy yyyy yyyy yyyy zzzz zzzz zzzz zzzz zzzz zzzz zzzz zzzz
#define vector80_x_y_z(x, y, z) emit5(0xf800|((x)&0x7ff), 0x0000|(((y)>>16)&0xffff), 0x0000|((y)&0xffff), 0x0000|(((z)>>16)&0xffff), 0x0000|((z)&0xffff))

// Repeat codes
#define REP1  (0x00)
#define REP2  (0x01)
#define REP4  (0x02)
#define REP8  (0x03)
#define REP16 (0x04)
#define REP32 (0x05)
#define REP64 (0x06)
#define REPLT (0x07)

// Register increment or not
#define INC   (0x01)
#define NOINC (0x00)

// width of memory op for vector instructions.
// This is different from scalar instructions (w_h etc)
#define W8  (0x00)
#define W16 (0x01)
#define W32 (0x02)

// Vector register codes
// H(y, 0)
#define Hy0   (0x00)
// V(y, 0)
#define Vy0   (0x01)
// H(y, 16)
#define Hy16  (0x02)
// ...
#define Vy16  (0x03)
#define Hy32  (0x04)
#define Vy32  (0x04)
#define Hy48  (0x06)
#define Vy48  (0x07)
#define HXy0  (0x08)
#define VXy0  (0x09)
#define HXy32 (0x0A)
#define VXy32 (0x0B)
#define HYy0  (0x0C)
#define VYy0  (0x0D)
// source reg, from scalar register
#define XSCALAR (0x0E)
// destination reg, ignore result
#define XNULL   (0x0E)

// flag operation
#define SETF    (1)
#define KEEPF   (0)

// ACC operation flags, use logic OR to combine
#define NOACC   (0)
// Add current ACC value to result, signed, saturate at 0x7fff
#define ADDACCSAT  ((0x07)<<3)
// Add without saturation?
#define ADDACC  ((0x05)<<3)
// Clear ACC on first iteration
#define CLRA    (0x04)
// Write current result to ACC
#define UPDACC  (0x02)
// Use subtract instead of add
#define SBA     (0x01)

// vld %s{D}y=%d{d}%s{G} %02x{g}, %d{(j*128)+k}(r%d{s}+=r%d{t}) %s{R} ; x=%02x{x} A=%03x{a} y=%02x{y} z=%04x{z}
// 1111 10xx 0xxx xRRR, DDDD dddd ddaa aaaa, aaaa yyyy ykkk kkkk, gggg GGut ttuu zzzz, zzzz zzzz zzzs ssjj 

// 1111 1000 000w wRRR, XXXX yyyy yy11 1000, 0000 0011 1kkk kkkk, 1111 i0ut ttuu 0000, 0000 0000 000s ssjj 
// u=0, sometimes u=4 
// z=0, sometimes 0xFE, 0x200, 0x300, 0x01, 0x04, 0x10
// w: width of memory op
// x: 1000=HX(y, 0), 1010=HX(y, 32), 1001=VX(y, 0), 1011=VX(y, 32) etc
// y: y-coordinate
// i: increment flag
// o: offset (9 bit)
// s: source pointer register (3 bit) r0..r7
// t: increment register (3 bit)
// r: repeat code 000..111
#define vld80(w, x, y, i, o, s, t, r) emit5(0xf800|((w)<<3)|(r), 0x0038|((x)<<12)|((y)<<6), 0x0380|((o)&0x007f), 0xf000|((i)<<11)|((t&7)<<6), ((s&7)<<2)|((o)>>7))

// To experiment with unknown stuff
#define vld80test(w, x, y, i, o, s, t, r, u, z) emit5(0xf800|((w)<<3)|(r), 0x0038|((x)<<12)|((y)<<6), 0x0380|((o)&0x007f), 0xf000|((i)<<11)|((t&7)<<6)|((u&3)<<4)|((u&4)<<7)|((z&0x7FFF)>>11), ((s&7)<<2)|((o)>>7)|((z&0x07FF)<<5))


// vst%s{w} %s{A}y=%d{a}%s{H} %02x{h}, %d{(j*128)+k}(r%d{s}+=r%d{t}) %s{R} ; x=%02x{x} D=%03x{d} y=%02x{y} z=%04x{z} u=%02x{u}"
// 1111 10xx 1xxw wRRR dddd dddd ddAA AAaa aaaa yyyy ykkk kkkk uttt uuhh hhHH zzzz zzzz zzzz zzzs ssjj "; 
// meistens D=380 y=7 z=0 u=0
// 1111 1000 100w wRRR, 1110 0000 00AA AAaa, aaaa 0011 1kkk kkkk, 0ttt 0011 11i0 0000, 0000 0000 000s ssjj "; 
// w: width of memory op
// x: X and register width
// y: y-Koordinate
// i: increment flag
// o: offset (9 bit)
// s: source pointer register (3 bit) r0..r7
// t: increment register (3 bit)
// r: repeat code 000..111
#define vst80(w, x, y, i, o, s, t, r) emit5(0xf880|((w)<<3)|(r), 0xe000|((x)<<2)|((y&0x30)>>4), 0x0380|((y&0xf)<<12)|((o)&0x007f), 0x03c0|((t&7)<<12)|((i)<<5), ((s&7)<<2)|((o)>>7))


// Vector 80 register op, only vector register -> no scalar register input
// 1111 11 u v:6 r:3 d:10 a:10 F 0 b:10 f_d:6 f_a:6 f_i:14 f_b:6
//    V<op> R_d, R_a, R_b {REP r}
// vr%s{v} %s{D}y=%d{d}%s{G} %02x{g}, %s{A}y=%d{a}%s{H} %02x{h}, %s{B}y=%d{b}%s{I} %02x{k} %s{R} %s{P} %s{F} #%x{x} %04x{z}"
//1111 11xv vvvv vRRR, DDDD dddd ddAA AAaa, aaaa F0BB BBbb bbbb, gggg GGhh hhHH zzzz, PPPz zzzz zzkk kkII
//1111 110v vvvv vRRR, DDDD dddd ddAA AAaa, aaaa F0BB BBbb bbbb, 1111 GG11 11hh axax, CCC0 fff0 0011 11II
//                                                                                       ^SRU_DEST 0=acc, 1=scalar reg
//                                                                                         ^^^ acc update function 000 = don't acc
//                                                                                            ^CLRA
//                                                                                              ^ACC update
//                                                                                               ^SBA subtract from acc
//                                                                                         ^^^ scalar reg update func
//                                                                                            ^^^ scalar reg to update
// GG HH II increments, CCC conditional execution
// axax lower 4 bits for x in R_a

// Simple version:
//1111 110v vvvv vRRR, DDDD dddd ddAA AAaa, aaaa 00BB BBbb bbbb, 1111 GG11 11hh 0000, 0000 0000 0011 11II
// op: operation v_add etc.
// dx, ax, bx: X and register width
// dy, ay, by: y coordinate
// di, ai, bi: increment flag
// r: repeat code
#define vr80(op, dx, dy, di, ax, ay, ai, bx, by, bi, r) emit5(0xfc00|((op)<<3)|(r), ((dx)<<12)|((dy)<<6)|((ax)<<2)|((ay)>>4), ((ay&0xF)<<12)|((bx)<<6)|(by), 0xF3C0|((di)<<11)|((ai)<<5), 0x003C|((bi)<<1))

// Same with condition code
#define vr80c(op, dx, dy, di, ax, ay, ai, bx, by, bi, r, c) emit5(0xfc00|((op)<<3)|(r), ((dx)<<12)|((dy)<<6)|((ax)<<2)|((ay)>>4), ((ay&0xF)<<12)|((bx)<<6)|(by), 0xF3C0|((di)<<11)|((ai)<<5), 0x003C|((c)<<13)|((bi)<<1))

// Scalar register update
//1111 110v vvvv vRRR, DDDD dddd ddAA AAaa, aaaa F0BB BBbb bbbb, 1111 GG11 11hh axax, CCC1 fff0 0011 11II
// op: operation v_add etc.
// dx, ax, bx: X and register width
// dy, ay, by: y coordinate
// di, ai, bi: increment flag
// axx: lower 4 bits for x in R_a
// r: repeat code
// c: condition code IFZ etc.
// f: flag operation SETF, KEEPF
// sru: scalar reg update func sru_*
// sreg: scalar reg to update r0..r7
#define vr80sru(op, dx, dy, di, ax, axx, ay, ai, bx, by, bi, r, c, f, sru, sreg) emit5(0xfc00|((op)<<3)|(r), ((dx)<<12)|((dy)<<6)|((ax)<<2)|((ay)>>4), ((ay&0xF)<<12)|((f)<<11)|((bx)<<6)|(by), 0xF3C0|((di)<<11)|((ai)<<5)|(axx&0xF), 0x103C|((c)<<13)|((sru)<<9)|((sreg&0x7)<<6)|((bi)<<1))

#define vr80acc(op, dx, dy, di, ax, axx, ay, ai, bx, by, bi, r, c, f, acc) emit5(0xfc00|((op)<<3)|(r), ((dx)<<12)|((dy)<<6)|((ax)<<2)|((ay)>>4), ((ay&0xF)<<12)|((f)<<11)|((bx)<<6)|(by), 0xF3C0|((di)<<11)|((ai)<<5)|(axx&0xF), 0x003C|((c)<<13)|((acc)<<6)|((bi)<<1))


// Immediate addressing
// 1111 11 u v:6 r:3 d:10 a:10 F 1 k:10 f_d:6 f_a:6 f_i:14 j:6
//    V<op> R_d, R_a, #(j<<10 | k) {REP r}
//    2nd operand is 16-bit immediate value; zero-extended
// vi%s{v} %s{D}y=%d{d}%s{G} %02x{g}, %s{A}y=%d{a}%s{H} %02x{h}, #%d{(k*1024)+l} %s{R} %s{P} %s{F} #%x{x} %04x{z}
// 1111 11xv vvvv vRRR, DDDD dddd ddAA AAaa, aaaa F1ll llll llll, gggg GGhh hhHH zzzz, PPPz zzzz zzkk kkkk
// 1111 110v vvvv vRRR, DDDD dddd ddAA AAaa, aaaa 01ll llll llll, gggg GGhh hhHH 0000 ,0000 0000 00kk kkkk
#define vi80(op, dx, dy, di, ax, ay, ai, i, r) emit5(0xfc00|((op)<<3)|(r), ((dx)<<12)|((dy)<<6)|((ax)<<2)|((ay)>>4), 0x0400|((ay&0xF)<<12)|(i&0x3FF), 0xF3C0|((di)<<11)|((ai)<<5), ((i)>>10))

// Immediate with ACC and condition
//1111 11xv vvvv vRRR, DDDD dddd ddAA AAaa, aaaa F1ll llll llll, gggg GGhh hhHH axax, CCC0 zzzz zzkk kkkk
//                                                                                         ^^^ acc update function 000 = don't acc
//                                                                                            ^CLRA
//                                                                                              ^ACC update
//                                                                                               ^SBA subtract from acc
#define vi80acc(op, dx, dy, di, ax, axx, ay, ai, i, r, c, f, acc) emit5(0xfc00|((op)<<3)|(r), ((dx)<<12)|((dy)<<6)|((ax)<<2)|((ay)>>4), 0x0400|((ay&0xF)<<12)|((f)<<11)|(i&0x3FF), 0xF3C0|((di)<<11)|((ai)<<5)|(axx&0xF), ((c)<<13)|((acc)<<6)|((i)>>10))

// Immediate with scalar register update
#define vi80sru(op, dx, dy, di, ax, axx, ay, ai, i, r, c, f, sru, sreg) emit5(0xfc00|((op)<<3)|(r), ((dx)<<12)|((dy)<<6)|((ax)<<2)|((ay)>>4), 0x0400|((ay&0xF)<<12)|((f)<<11)|(i&0x3FF), 0xF3C0|((di)<<11)|((ai)<<5)|(axx&0xF), 0x1000|((c)<<13)|((sru)<<9)|((sreg&0x7)<<6)|((i)>>10))

// ; vector48 0x%x{x}, 0x%x{y}
// 1111 0xxx xxxx xxxx yyyy yyyy yyyy yyyy yyyy yyyy yyyy yyyy
#define vector48_x_y(x, y) emit3(0xf000|((x)&0x7ff), 0x0000|(((y)>>16)&0xffff), 0x0000|((y)&0xffff))

// ; scalar48 0x%x{x}, 0x%x{y}
// 1110 xxxx xxxx xxxx yyyy yyyy yyyy yyyy yyyy yyyy yyyy yyyy
#define scalar48_x_y(x, y) emit3(0xe000|((x)&0xfff), 0x0000|(((y)>>16)&0xffff), 0x0000|((y)&0xffff))

// ; scalar32 0x%x{x}, 0x%x{y}
// 1xxx xxxx xxxx xxxx yyyy yyyy yyyy yyyy
#define scalar32_x_y(x, y) emit2(0x8000|((x)&0x7fff), 0x0000|((y)&0xffff))

// ; scalar16 0x%x{x}
// 0xxx xxxx xxxx xxxx
#define scalar16_x(x) emit1(0x0000|((x)&0x7fff))

/* End of Autogenerated Code */
