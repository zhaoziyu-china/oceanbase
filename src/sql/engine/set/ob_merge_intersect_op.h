/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef OCEANBASE_BASIC_OB_SET_OB_MERGE_INTERSECT_OP_H_
#define OCEANBASE_BASIC_OB_SET_OB_MERGE_INTERSECT_OP_H_

#include "sql/engine/set/ob_merge_set_op.h"

namespace oceanbase {
namespace sql {

class ObMergeIntersectSpec : public ObMergeSetSpec {
  OB_UNIS_VERSION_V(1);

  public:
  ObMergeIntersectSpec(common::ObIAllocator& alloc, const ObPhyOperatorType type);
};

class ObMergeIntersectOp : public ObMergeSetOp {
  public:
  ObMergeIntersectOp(ObExecContext& exec_ctx, const ObOpSpec& spec, ObOpInput* input);

  virtual int inner_open() override;
  virtual int inner_close() override;
  virtual int rescan() override;
  virtual void destroy() override;
  virtual int inner_get_next_row() override;

  private:
  bool right_iter_end_;
  bool first_got_right_row_;
};

}  // end namespace sql
}  // end namespace oceanbase

#endif /* OCEANBASE_BASIC_OB_SET_OB_MERGE_INTERSECT_OP_H_ */