#ifndef MACS_H
# define MACS_H

# define NULL_GUARD(val)  if (val == NULL) return NULL
# define NULL_GUARD_NR(val) if (val == NULL) return
# define ERR_CHECK(val, err) if (val == err) return NULL
# define ERR_CNR(val, err, ret) if (val == err) return (ret)
# define ERR_NR(val, err) if (val == err) return

# define BREAK(val, err) if (val == err) break
# define IF_RET(val, ret) if (val) return (ret)
# define IF(bool, true) if ((bool)) { true; }
# define EIF(bool, true) else if ((bool)) {true;}
# define ELSE(expr) else { expr; }
# define IFTR(bool, true, ret) if ((bool)) { true; return (ret);}
# define IFE(bool, true, false) if ((bool)) { true; } else { false ;}
# define CA(bool, var, true, false) if ((bool)) { var = true; } else { var = false; }

#endif