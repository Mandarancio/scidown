#include "noop.h"

#include <string.h>

/* Block constructs */
static void rndr_paragraph(void *target, void *content, int is_tight, const hoedown_renderer_data *data) {}
static void rndr_indented_code_block(void *target, const hoedown_buffer *code, const hoedown_renderer_data *data) {}
static void rndr_fenced_code_block(void *target, const hoedown_buffer *code, const hoedown_buffer *info, const hoedown_renderer_data *data) {}
static void rndr_horizontal_rule(void *target, const hoedown_renderer_data *data) {}
static void rndr_atx_header(void *target, void *content, size_t level, const hoedown_renderer_data *data) {}
static void rndr_setext_header(void *target, void *content, int is_double, const hoedown_renderer_data *data) {}
static void rndr_list(void *target, void *content, int is_ordered, int is_tight, int start, const hoedown_renderer_data *data) {}
static void rndr_list_item(void *target, void *content, int is_ordered, int is_tight, const hoedown_renderer_data *data) {}
static void rndr_quote_block(void *target, void *content, const hoedown_renderer_data *data) {}
static void rndr_html_block(void *target, const hoedown_buffer *html, const hoedown_renderer_data *data) {}

/* Inline constructs */
static void rndr_string(void *target, const hoedown_buffer *text, const hoedown_renderer_data *data) {}
static void rndr_escape(void *target, uint8_t character, const hoedown_renderer_data *data) {}
static void rndr_hard_linebreak(void *target, const hoedown_renderer_data *data) {}
static void rndr_linebreak(void *target, const hoedown_renderer_data *data) {}
static void rndr_uri_autolink(void *target, const hoedown_buffer *uri, const hoedown_renderer_data *data) {}
static void rndr_email_autolink(void *target, const hoedown_buffer *email, const hoedown_renderer_data *data) {}
static void rndr_html(void *target, const hoedown_buffer *html, const hoedown_renderer_data *data) {}
static void rndr_entity(void *target, const hoedown_buffer *character, const hoedown_renderer_data *data) {}
static void rndr_code_span(void *target, const hoedown_buffer *code, const hoedown_renderer_data *data) {}
static void rndr_emphasis(void *target, void *content, size_t level, const hoedown_renderer_data *data) {}
static void rndr_link(void *target, void *content, const hoedown_buffer *dest, const hoedown_buffer *title, int is_image, const hoedown_renderer_data *data) {}

/* Global callbacks */
static void *object_get(int is_inline, const hoedown_renderer_data *data) { return NULL; }
static void object_merge(void *target, void *content, int is_inline, const hoedown_renderer_data *data) {}
static void object_pop(void *target, int is_inline, const hoedown_renderer_data *data) {}

static void render_start(int is_inline, const hoedown_renderer_data *data) {}
static void *render_end(void *target, int is_inline, const hoedown_renderer_data *data) { return NULL; }


/* Exported API */
hoedown_renderer *hoedown_noop_renderer_new() {
  static const hoedown_renderer temp = {
    NULL,

    rndr_paragraph,
    rndr_indented_code_block,
    rndr_fenced_code_block,
    rndr_horizontal_rule,
    rndr_atx_header,
    rndr_setext_header,
    rndr_list,
    rndr_list_item,
    rndr_quote_block,
    rndr_html_block,

    rndr_string,
    rndr_escape,
    rndr_hard_linebreak,
    rndr_linebreak,
    rndr_uri_autolink,
    rndr_email_autolink,
    rndr_html,
    rndr_entity,
    rndr_code_span,
    rndr_emphasis,
    rndr_link,

    object_get,
    object_merge,
    object_pop,

    render_start,
    render_end,
  };

  hoedown_renderer *rndr = hoedown_malloc(sizeof(hoedown_renderer));
  memcpy(rndr, &temp, sizeof(hoedown_renderer));
  return rndr;
}

void hoedown_noop_renderer_free(hoedown_renderer *rndr) {
  free(rndr);
}