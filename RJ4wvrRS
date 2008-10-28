BNF >> Grammar >> for >> ISO/IEC >> 9075-2:(2003 >> -Database >> Language >> SQL >> SQL-2003 >> SQL)/Foundation=====================================================================================@(#)$Id:sql-2003-2.bnf,v >> 1.11 >> 2005/07/13 >> 18:37:30 >> jleffler >> Exp$
;;;


SQLTerminalCharacter = SQLLanguageCharacter
;;;


SQLLanguageCharacter = SimpleLatinLetter
  | Digit
  | SQLSpecialCharacter
;;;


SimpleLatinLetter = SimpleLatinUpperCaseLetter
  | SimpleLatinLowerCaseLetter
;;;


SimpleLatinUpperCaseLetter = A
  | B
  | C
  | D
  | E
  | F
  | G
  | H
  | I
  | J
  | K
  | L
  | M
  | N
  | O
  | P
  | Q
  | R
  | S
  | T
  | U
  | V
  | W
  | X
  | Y
  | Z
;;;


SimpleLatinLowerCaseLetter = A
  | B
  | C
  | D
  | E
  | F
  | G
  | H
  | I
  | J
  | K
  | L
  | M
  | N
  | O
  | P
  | Q
  | R
  | S
  | T
  | U
  | V
  | W
  | X
  | Y
  | Z
;;;


Digit = 0
  | 1
  | 2
  | 3
  | 4
  | 5
  | 6
  | 7
  | 8
  | 9
;;;


SQLSpecialCharacter = Space
  | DoubleQuote
  | Percent
  | Ampersand
  | Quote
  | LeftParen
  | RightParen
  | Asterisk
  | PlusSign
  | Comma
  | MinusSign
  | Period
  | Solidus
  | Colon
  | Semicolon
  | LessThanOperator
  | EqualsOperator
  | GreaterThanOperator
  | QuestionMark
  | LeftBracket
  | RightBracket
  | Circumflex
  | Underscore
  | VerticalBar
  | LeftBrace
  | RightBrace
;;;


Space = !!See >> the >> Syntax >> Rules
;;;


DoubleQuote = "
;;;


Percent = %
;;;


Ampersand = &
;;;


Quote = '
;;;


LeftParen = (
;;;


RightParen = )
;;;


Asterisk = *
;;;


PlusSign = +
;;;


Comma = ,
;;;


MinusSign = -
;;;


Period = .
;;;


Solidus = /
;;;


Colon = :
;;;


Semicolon = ;
;;;


LessThanOperator = (
;;;


EqualsOperator = =
;;;


GreaterThanOperator = )
;;;


QuestionMark = ?
;;;


Token = NondelimiterToken
  | DelimiterToken
;;;


NondelimiterToken = RegularIdentifier
  | KeyWord
  | UnsignedNumericLiteral
  | NationalCharacterStringLiteral
  | BitStringLiteral
  | HexStringLiteral
  | LargeObjectLengthToken
  | Multiplier
;;;


RegularIdentifier = IdentifierBody
;;;


IdentifierBody = (IdentifierStart >> *IdentifierPart)
;;;


IdentifierPart = IdentifierStart
  | IdentifierExtend
;;;


IdentifierStart = !!See >> The >> Syntax >> Rules
;;;


IdentifierExtend = !!See >> The >> Syntax >> Rules
;;;


LargeObjectLengthToken = +Digit >> Multiplier
;;;


Multiplier = K
  | M
  | G
;;;


UnicodeDelimitedIdentifier = (U >> Ampersand >> DoubleQuote >> +UnicodeDelimiterBody >> DoubleQuote >> !ESCAPE >> EscapeCharacter)
;;;


UnicodeDelimiterBody = +UnicodeIdentifierPart
;;;


UnicodeIdentifierPart = DelimitedIdentifierPart
  | UnicodeEscapeValue
;;;


UnicodeEscapeValue = Unicode4DigitEscapeValue
  | Unicode6DigitEscapeValue
;;;


Unicode4DigitEscapeValue = EscapeCharacter >> Hexit >> Hexit >> Hexit >> Hexit
;;;


Unicode6DigitEscapeValue = EscapeCharacter >> PlusSign >> Hexit >> Hexit >> Hexit >> Hexit >> Hexit >> Hexit
;;;


EscapeCharacter = !!See >> The >> Syntax >> Rules
;;;


NondoublequoteCharacter = !!See >> The >> Syntax >> Rules
;;;


DoublequoteSymbol = DoubleQuote >> DoubleQuote
;;;


DelimiterToken = CharacterStringLiteral
  | DateString
  | TimeString
  | TimestampString
  | IntervalString
  | DelimitedIdentifier
  | UnicodeDelimitedIdentifier
  | SQLSpecialCharacter
  | NotEqualsOperator
  | GreaterThanOrEqualsOperator
  | LessThanOrEqualsOperator
  | ConcatenationOperator
  | RightArrow
  | LeftBracketTrigraph
  | RightBracketTrigraph
  | DoubleColon
  | DoublePeriod
;;;


NotEqualsOperator = LessThanOperator >> GreaterThanOperator
;;;


GreaterThanOrEqualsOperator = GreaterThanOperator >> EqualsOperator
;;;


LessThanOrEqualsOperator = LessThanOperator >> EqualsOperator
;;;


ConcatenationOperator = VerticalBar >> VerticalBar
;;;


RightArrow = MinusSign >> GreaterThanOperator
;;;


DoubleColon = Colon >> Colon
;;;


DoublePeriod = Period >> Period
;;;


Separator = +(Comment
  | WhiteSpace)
;;;


Comment = SimpleComment
  | BracketedComment
;;;


SimpleComment = (SimpleCommentIntroducer >> *CommentCharacter >> Newline)
;;;


SimpleCommentIntroducer = (MinusSign >> MinusSign >> *MinusSign)
;;;


BracketedComment = BracketedCommentIntroducer >> BracketedCommentContents >> BracketedCommentTerminator
;;;


BracketedCommentIntroducer = Slash >> Asterisk
;;;


BracketedCommentTerminator = Asterisk >> Slash
;;;


BracketedCommentContents = *((CommentCharacter
  | Separator))
;;;


CommentCharacter = NonquoteCharacter
  | Quote
;;;


Newline = !!See >> the >> Syntax >> Rules
;;;


KeyWord = ReservedWord
  | NonReservedWord
;;;


NonReservedWord = A
  | ABS
  | ABSOLUTE
  | ACTION
  | ADA
  | ADMIN
  | AFTER
  | ALWAYS
  | ASC
  | ASSERTION
  | ASSIGNMENT
  | ATTRIBUTE
  | ATTRIBUTES
  | AVG
  | BEFORE
  | BERNOULLI
  | BREADTH
  | C
  | CARDINALITY
  | CASCADE
  | CATALOG
  | CATALOG_NAME
  | CEIL
  | CEILING
  | CHAIN
  | CHARACTERISTICS
  | CHARACTERS
  | CHARACTER_LENGTH
  | CHARACTER_SET_CATALOG
  | CHARACTER_SET_NAME
  | CHARACTER_SET_SCHEMA
  | CHAR_LENGTH
  | CHECKED
  | CLASS_ORIGIN
  | COALESCE
  | COBOL
  | CODE_UNITS
  | COLLATION
  | COLLATION_CATALOG
  | COLLATION_NAME
  | COLLATION_SCHEMA
  | COLLECT
  | COLUMN_NAME
  | COMMAND_FUNCTION
  | COMMAND_FUNCTION_CODE
  | COMMITTED
  | CONDITION
  | CONDITION_NUMBER
  | CONNECTION_NAME
  | CONSTRAINTS
  | CONSTRAINT_CATALOG
  | CONSTRAINT_NAME
  | CONSTRAINT_SCHEMA
  | CONSTRUCTORS
  | CONTAINS
  | CONVERT
  | CORR
  | COUNT
  | COVAR_POP
  | COVAR_SAMP
  | CUME_DIST
  | CURRENT_COLLATION
  | CURSOR_NAME
  | DATA
  | DATETIME_INTERVAL_CODE
  | DATETIME_INTERVAL_PRECISION
  | DEFAULTS
  | DEFERRABLE
  | DEFERRED
  | DEFINED
  | DEFINER
  | DEGREE
  | DENSE_RANK
  | DEPTH
  | DERIVED
  | DESC
  | DESCRIPTOR
  | DIAGNOSTICS
  | DISPATCH
  | DOMAIN
  | DYNAMIC_FUNCTION
  | DYNAMIC_FUNCTION_CODE
  | EQUALS
  | EVERY
  | EXCEPTION
  | EXCLUDE
  | EXCLUDING
  | EXP
  | EXTRACT
  | FINAL
  | FIRST
  | FLOOR
  | FOLLOWING
  | FORTRAN
  | FOUND
  | FUSION
  | G
  | GENERAL
  | GO
  | GOTO
  | GRANTED
  | HIERARCHY
  | IMPLEMENTATION
  | INCLUDING
  | INCREMENT
  | INITIALLY
  | INSTANCE
  | INSTANTIABLE
  | INTERSECTION
  | INVOKER
  | ISOLATION
  | K
  | KEY
  | KEY_MEMBER
  | KEY_TYPE
  | LAST
  | LENGTH
  | LEVEL
  | LN
  | LOCATOR
  | LOWER
  | M
  | MAP
  | MATCHED
  | MAX
  | MAXVALUE
  | MESSAGE_LENGTH
  | MESSAGE_OCTET_LENGTH
  | MESSAGE_TEXT
  | MIN
  | MINVALUE
  | MOD
  | MORE
  | MUMPS
  | NAME
  | NAMES
  | NESTING
  | NEXT
  | NORMALIZE
  | NORMALIZED
  | NULLABLE
  | NULLIF
  | NULLS
  | NUMBER
  | OBJECT
  | OCTETS
  | OCTET_LENGTH
  | OPTION
  | OPTIONS
  | ORDERING
  | ORDINALITY
  | OTHERS
  | OVERLAY
  | OVERRIDING
  | PAD
  | PARAMETER_MODE
  | PARAMETER_NAME
  | PARAMETER_ORDINAL_POSITION
  | PARAMETER_SPECIFIC_CATALOG
  | PARAMETER_SPECIFIC_NAME
  | PARAMETER_SPECIFIC_SCHEMA
  | PARTIAL
  | PASCAL
  | PATH
  | PERCENTILE_CONT
  | PERCENTILE_DISC
  | PERCENT_RANK
  | PLACING
  | PLI
  | POSITION
  | POWER
  | PRECEDING
  | PRESERVE
  | PRIOR
  | PRIVILEGES
  | PUBLIC
  | RANK
  | READ
  | REGR_AVGX
  | REGR_AVGY
  | REGR_COUNT
  | REGR_INTERCEPT
  | REGR_R2
  | REGR_SLOPE
  | REGR_SXX
  | REGR_SXY
  | REGR_SXY
  | RELATIVE
  | REPEATABLE
  | RESTART
  | RESULT
  | RETURNED_CARDINALITY
  | RETURNED_LENGTH
  | RETURNED_OCTET_LENGTH
  | RETURNED_SQLSTATE
  | ROLE
  | ROUTINE
  | ROUTINE_CATALOG
  | ROUTINE_NAME
  | ROUTINE_SCHEMA
  | ROW_COUNT
  | ROW_NUMBER
  | SCALE
  | SCHEMA
  | SCHEMA_NAME
  | SCOPE_CATALOG
  | SCOPE_NAME
  | SCOPE_SCHEMA
  | SECTION
  | SECURITY
  | SELF
  | SEQUENCE
  | SERIALIZABLE
  | SERVER_NAME
  | SESSION
  | SETS
  | SIMPLE
  | SIZE
  | SOURCE
  | SPACE
  | SPECIFIC_NAME
  | SQRT
  | STATE
  | STATEMENT
  | STDDEV_POP
  | STDDEV_SAMP
  | STRUCTURE
  | STYLE
  | SUBCLASS_ORIGIN
  | SUBSTRING
  | SUM
  | TABLESAMPLE
  | TABLE_NAME
  | TEMPORARY
  | TIES
  | TOP_LEVEL_COUNT
  | TRANSACTION
  | TRANSACTIONS_COMMITTED
  | TRANSACTIONS_ROLLED_BACK
  | TRANSACTION_ACTIVE
  | TRANSFORM
  | TRANSFORMS
  | TRANSLATE
  | TRIGGER_CATALOG
  | TRIGGER_NAME
  | TRIGGER_SCHEMA
  | TRIM
  | TYPE
  | UNBOUNDED
  | UNCOMMITTED
  | UNDER
  | UNNAMED
  | UPPER
  | USAGE
  | USER_DEFINED_TYPE_CATALOG
  | USER_DEFINED_TYPE_CODE
  | USER_DEFINED_TYPE_NAME
  | USER_DEFINED_TYPE_SCHEMA
  | VAR_POP
  | VAR_SAMP
  | VIEW
  | WIDTH_BUCKET
  | WORK
  | WRITE
  | ZONE
;;;


ReservedWord = ADD
  | ALL
  | ALLOCATE
  | ALTER
  | AND
  | ANY
  | ARE
  | ARRAY
  | AS
  | ASENSITIVE
  | ASYMMETRIC
  | AT
  | ATOMIC
  | AUTHORIZATION
  | BEGIN
  | BETWEEN
  | BIGINT
  | BINARY
  | BLOB
  | BOOLEAN
  | BOTH
  | BY
  | CALL
  | CALLED
  | CASCADED
  | CASE
  | CAST
  | CHAR
  | CHARACTER
  | CHECK
  | CLOB
  | CLOSE
  | COLLATE
  | COLUMN
  | COMMIT
  | CONNECT
  | CONSTRAINT
  | CONTINUE
  | CORRESPONDING
  | CREATE
  | CROSS
  | CUBE
  | CURRENT
  | CURRENT_DATE
  | CURRENT_DEFAULT_TRANSFORM_GROUP
  | CURRENT_PATH
  | CURRENT_ROLE
  | CURRENT_TIME
  | CURRENT_TIMESTAMP
  | CURRENT_TRANSFORM_GROUP_FOR_TYPE
  | CURRENT_USER
  | CURSOR
  | CYCLE
  | DATE
  | DAY
  | DEALLOCATE
  | DEC
  | DECIMAL
  | DECLARE
  | DEFAULT
  | DELETE
  | DEREF
  | DESCRIBE
  | DETERMINISTIC
  | DISCONNECT
  | DISTINCT
  | DOUBLE
  | DROP
  | DYNAMIC
  | EACH
  | ELEMENT
  | ELSE
  | END
  | (END >> -EXEC)
  | ESCAPE
  | EXCEPT
  | EXEC
  | EXECUTE
  | EXISTS
  | EXTERNAL
  | FALSE
  | FETCH
  | FILTER
  | FLOAT
  | FOR
  | FOREIGN
  | FREE
  | FROM
  | FULL
  | FUNCTION
  | GET
  | GLOBAL
  | GRANT
  | GROUP
  | GROUPING
  | HAVING
  | HOLD
  | HOUR
  | IDENTITY
  | IMMEDIATE
  | IN
  | INDICATOR
  | INNER
  | INOUT
  | INPUT
  | INSENSITIVE
  | INSERT
  | INT
  | INTEGER
  | INTERSECT
  | INTERVAL
  | INTO
  | IS
  | ISOLATION
  | JOIN
  | LANGUAGE
  | LARGE
  | LATERAL
  | LEADING
  | LEFT
  | LIKE
  | LOCAL
  | LOCALTIME
  | LOCALTIMESTAMP
  | MATCH
  | MEMBER
  | MERGE
  | METHOD
  | MINUTE
  | MODIFIES
  | MODULE
  | MONTH
  | MULTISET
  | NATIONAL
  | NATURAL
  | NCHAR
  | NCLOB
  | NEW
  | NO
  | NONE
  | NOT
  | NULL
  | NUMERIC
  | OF
  | OLD
  | ON
  | ONLY
  | OPEN
  | OR
  | ORDER
  | OUT
  | OUTER
  | OUTPUT
  | OVER
  | OVERLAPS
  | PARAMETER
  | PARTITION
  | PRECISION
  | PREPARE
  | PRIMARY
  | PROCEDURE
  | RANGE
  | READS
  | REAL
  | RECURSIVE
  | REF
  | REFERENCES
  | REFERENCING
  | RELEASE
  | RETURN
  | RETURNS
  | REVOKE
  | RIGHT
  | ROLLBACK
  | ROLLUP
  | ROW
  | ROWS
  | SAVEPOINT
  | SCROLL
  | SEARCH
  | SECOND
  | SELECT
  | SENSITIVE
  | SESSION_USER
  | SET
  | SIMILAR
  | SMALLINT
  | SOME
  | SPECIFIC
  | SPECIFICTYPE
  | SQL
  | SQLEXCEPTION
  | SQLSTATE
  | SQLWARNING
  | START
  | STATIC
  | SUBMULTISET
  | SYMMETRIC
  | SYSTEM
  | SYSTEM_USER
  | TABLE
  | THEN
  | TIME
  | TIMESTAMP
  | TIMEZONE_HOUR
  | TIMEZONE_MINUTE
  | TO
  | TRAILING
  | TRANSLATION
  | TREAT
  | TRIGGER
  | TRUE
  | UNION
  | UNIQUE
  | UNKNOWN
  | UNNEST
  | UPDATE
  | USER
  | USING
  | VALUE
  | VALUES
  | VARCHAR
  | VARYING
  | WHEN
  | WHENEVER
  | WHERE
  | WINDOW
  | WITH
  | WITHIN
  | WITHOUT
  | YEAR
;;;


Literal = SignedNumericLiteral
  | GeneralLiteral
;;;


UnsignedLiteral = UnsignedNumericLiteral
  | GeneralLiteral
;;;


GeneralLiteral = CharacterStringLiteral
  | NationalCharacterStringLiteral
  | UnicodeCharacterStringLiteral
  | BinaryStringLiteral
  | DatetimeLiteral
  | IntervalLiteral
  | BooleanLiteral
;;;


CharacterStringLiteral = !(Introducer >> CharacterSetSpecification >> Quote >> *CharacterRepresentation >> Quote >> *((Separator >> Quote >> *CharacterRepresentation >> Quote)))
;;;


Introducer = Underscore
;;;


CharacterRepresentation = NonquoteCharacter
  | QuoteSymbol
;;;


NonquoteCharacter = !!See >> The >> Syntax >> Rules
;;;


QuoteSymbol = Quote >> Quote
;;;


NationalCharacterStringLiteral = (N >> Quote >> *CharacterRepresentation >> Quote >> *((Separator >> Quote >> *CharacterRepresentation >> Quote)))
;;;


UnicodeCharacterStringLiteral = !(Introducer >> CharacterSetSpecification >> U >> Ampersand >> Quote >> *UnicodeRepresentation >> Quote >> *((Separator >> Quote >> *UnicodeRepresentation >> Quote)) >> !ESCAPE >> EscapeCharacter)
;;;


UnicodeRepresentation = CharacterRepresentation
  | UnicodeEscapeValue
;;;


BinaryStringLiteral = (X >> Quote >> *(Hexit >> Hexit) >> Quote >> *((Separator >> Quote >> *(Hexit >> Hexit) >> Quote)) >> !ESCAPE >> EscapeCharacter)
;;;


Hexit = Digit
  | A
  | B
  | C
  | D
  | E
  | F
  | A
  | B
  | C
  | D
  | E
  | F
;;;


SignedNumericLiteral = !(Sign >> UnsignedNumericLiteral)
;;;


UnsignedNumericLiteral = ExactNumericLiteral
  | ApproximateNumericLiteral
;;;


ExactNumericLiteral = (UnsignedInteger >> !(Period >> !UnsignedInteger))
  | Period >> UnsignedInteger
;;;


Sign = PlusSign
  | MinusSign
;;;


ApproximateNumericLiteral = Mantissa >> E >> Exponent
;;;


Mantissa = ExactNumericLiteral
;;;


Exponent = SignedInteger
;;;


SignedInteger = !(Sign >> UnsignedInteger)
;;;


DatetimeLiteral = DateLiteral
  | TimeLiteral
  | TimestampLiteral
;;;


DateLiteral = DATE >> DateString
;;;


TimeLiteral = TIME >> TimeString
;;;


TimestampLiteral = TIMESTAMP >> TimestampString
;;;


DateString = Quote >> UnquotedDateString >> Quote
;;;


TimeString = Quote >> UnquotedTimeString >> Quote
;;;


TimestampString = Quote >> UnquotedTimestampString >> Quote
;;;


TimeZoneInterval = Sign >> HoursValue >> Colon >> MinutesValue
;;;


DateValue = YearsValue >> MinusSign >> MonthsValue >> MinusSign >> DaysValue
;;;


TimeValue = HoursValue >> Colon >> MinutesValue >> Colon >> SecondsValue
;;;


IntervalLiteral = (INTERVAL >> !Sign >> IntervalString >> IntervalQualifier)
;;;


IntervalString = Quote >> UnquotedIntervalString >> Quote
;;;


UnquotedDateString = DateValue
;;;


UnquotedTimeString = (TimeValue >> !TimeZoneInterval)
;;;


UnquotedTimestampString = UnquotedDateString >> Space >> UnquotedTimeString
;;;


UnquotedIntervalString = !(Sign >> YearMonthLiteral
  | DayTimeLiteral)
;;;


YearMonthLiteral = YearsValue
  | !(YearsValue >> MinusSign >> MonthsValue)
;;;


DayTimeLiteral = DayTimeInterval
  | TimeInterval
;;;


DayTimeInterval = (DaysValue >> !(Space >> HoursValue >> !(Colon >> MinutesValue >> !Colon >> SecondsValue)))
;;;


TimeInterval = (HoursValue >> !(Colon >> MinutesValue >> !Colon >> SecondsValue))
  | (MinutesValue >> !Colon >> SecondsValue)
  | SecondsValue
;;;


YearsValue = DatetimeValue
;;;


MonthsValue = DatetimeValue
;;;


DaysValue = DatetimeValue
;;;


HoursValue = DatetimeValue
;;;


MinutesValue = DatetimeValue
;;;


SecondsValue = (SecondsIntegerValue >> !(Period >> !SecondsFraction))
;;;


SecondsIntegerValue = UnsignedInteger
;;;


SecondsFraction = UnsignedInteger
;;;


DatetimeValue = UnsignedInteger
;;;


BooleanLiteral = TRUE
  | FALSE
  | UNKNOWN
;;;


Identifier = ActualIdentifier
;;;


ActualIdentifier = RegularIdentifier
  | DelimitedIdentifier
;;;


SQLLanguageIdentifier = (SQLLanguageIdentifierStart >> *(Underscore
  | SQLLanguageIdentifierPart))
;;;


SQLLanguageIdentifierStart = SimpleLatinLetter
;;;


SQLLanguageIdentifierPart = SimpleLatinLetter
  | Digit
;;;


AuthorizationIdentifier = RoleName
  | UserIdentifier
;;;


TableName = LocalOrSchemaQualifiedName
;;;


DomainName = SchemaQualifiedName
;;;


SchemaName = !(CatalogName >> Period >> UnqualifiedSchemaName)
;;;


CatalogName = Identifier
;;;


SchemaQualifiedName = !(SchemaName >> Period >> QualifiedIdentifier)
;;;


LocalOrSchemaQualifiedName = !(LocalOrSchemaQualifier >> Period >> QualifiedIdentifier)
;;;


LocalOrSchemaQualifier = SchemaName
  | MODULE
;;;


QualifiedIdentifier = Identifier
;;;


ColumnName = Identifier
;;;


CorrelationName = Identifier
;;;


QueryName = Identifier
;;;


SQLClientModuleName = Identifier
;;;


ProcedureName = Identifier
;;;


SchemaQualifiedRoutineName = SchemaQualifiedName
;;;


MethodName = Identifier
;;;


SpecificName = SchemaQualifiedName
;;;


CursorName = LocalQualifiedName
;;;


LocalQualifiedName = !(LocalQualifier >> Period >> QualifiedIdentifier)
;;;


LocalQualifier = MODULE
;;;


HostParameterName = Colon >> Identifier
;;;


SQLParameterName = Identifier
;;;


ConstraintName = SchemaQualifiedName
;;;


ExternalRoutineName = Identifier
  | CharacterStringLiteral
;;;


TriggerName = SchemaQualifiedName
;;;


CollationName = SchemaQualifiedName
;;;


CharacterSetName = !(SchemaName >> Period >> SQLLanguageIdentifier)
;;;


TransliterationName = SchemaQualifiedName
;;;


TranscodingName = SchemaQualifiedName
;;;


UserDefinedTypeName = SchemaQualifiedTypeName
;;;


SchemaResolvedUserDefinedTypeName = UserDefinedTypeName
;;;


SchemaQualifiedTypeName = !(SchemaName >> Period >> QualifiedIdentifier)
;;;


AttributeName = Identifier
;;;


FieldName = Identifier
;;;


SavepointName = Identifier
;;;


SequenceGeneratorName = SchemaQualifiedName
;;;


RoleName = Identifier
;;;


UserIdentifier = Identifier
;;;


ConnectionName = SimpleValueSpecification
;;;


SQLServerName = SimpleValueSpecification
;;;


ConnectionUserName = SimpleValueSpecification
;;;


SQLStatementName = StatementName
  | ExtendedStatementName
;;;


StatementName = Identifier
;;;


ExtendedStatementName = !(ScopeOption >> SimpleValueSpecification)
;;;


DynamicCursorName = CursorName
  | ExtendedCursorName
;;;


ExtendedCursorName = !(ScopeOption >> SimpleValueSpecification)
;;;


DescriptorName = !(ScopeOption >> SimpleValueSpecification)
;;;


ScopeOption = GLOBAL
  | LOCAL
;;;


WindowName = Identifier
;;;


DataType = PredefinedType
  | RowType
  | PathResolvedUserDefinedTypeName
  | ReferenceType
  | CollectionType
;;;


PredefinedType = (CharacterStringType >> !CHARACTER >> SET >> CharacterSetSpecification >> !CollateClause)
  | (NationalCharacterStringType >> !CollateClause)
  | BinaryLargeObjectStringType
  | NumericType
  | BooleanType
  | DatetimeType
  | IntervalType
;;;


CharacterStringType = (CHARACTER >> !LeftParen >> Length >> RightParen)
  | (CHAR >> !LeftParen >> Length >> RightParen)
  | CHARACTER >> VARYING >> LeftParen >> Length >> RightParen
  | CHAR >> VARYING >> LeftParen >> Length >> RightParen
  | VARCHAR >> LeftParen >> Length >> RightParen
  | (CHARACTER >> LARGE >> OBJECT >> !LeftParen >> LargeObjectLength >> RightParen)
  | (CHAR >> LARGE >> OBJECT >> !LeftParen >> LargeObjectLength >> RightParen)
  | (CLOB >> !LeftParen >> LargeObjectLength >> RightParen)
;;;


NationalCharacterStringType = (NATIONAL >> CHARACTER >> !LeftParen >> Length >> RightParen)
  | (NATIONAL >> CHAR >> !LeftParen >> Length >> RightParen)
  | (NCHAR >> !LeftParen >> Length >> RightParen)
  | NATIONAL >> CHARACTER >> VARYING >> LeftParen >> Length >> RightParen
  | NATIONAL >> CHAR >> VARYING >> LeftParen >> Length >> RightParen
  | NCHAR >> VARYING >> LeftParen >> Length >> RightParen
  | (NATIONAL >> CHARACTER >> LARGE >> OBJECT >> !LeftParen >> LargeObjectLength >> RightParen)
  | (NCHAR >> LARGE >> OBJECT >> !LeftParen >> LargeObjectLength >> RightParen)
  | (NCLOB >> !LeftParen >> LargeObjectLength >> RightParen)
;;;


BinaryLargeObjectStringType = (BINARY >> LARGE >> OBJECT >> !LeftParen >> LargeObjectLength >> RightParen)
  | (BLOB >> !LeftParen >> LargeObjectLength >> RightParen)
;;;


NumericType = ExactNumericType
  | ApproximateNumericType
;;;


ExactNumericType = (NUMERIC >> !(LeftParen >> Precision >> !Comma >> Scale >> RightParen))
  | (DECIMAL >> !(LeftParen >> Precision >> !Comma >> Scale >> RightParen))
  | (DEC >> !(LeftParen >> Precision >> !Comma >> Scale >> RightParen))
  | SMALLINT
  | INTEGER
  | INT
  | BIGINT
;;;


ApproximateNumericType = (FLOAT >> !LeftParen >> Precision >> RightParen)
  | REAL
  | DOUBLE >> PRECISION
;;;


Length = UnsignedInteger
;;;


LargeObjectLength = (UnsignedInteger >> !Multiplier >> !CharLengthUnits)
  | (LargeObjectLengthToken >> !CharLengthUnits)
;;;


CharLengthUnits = CHARACTERS
  | CODE_UNITS
  | OCTETS
;;;


Precision = UnsignedInteger
;;;


Scale = UnsignedInteger
;;;


BooleanType = BOOLEAN
;;;


DatetimeType = DATE
  | (TIME >> !LeftParen >> TimePrecision >> RightParen >> !WithOrWithoutTimeZone)
  | (TIMESTAMP >> !LeftParen >> TimestampPrecision >> RightParen >> !WithOrWithoutTimeZone)
;;;


WithOrWithoutTimeZone = WITH >> TIME >> ZONE
  | WITHOUT >> TIME >> ZONE
;;;


TimePrecision = TimeFractionalSecondsPrecision
;;;


TimestampPrecision = TimeFractionalSecondsPrecision
;;;


TimeFractionalSecondsPrecision = UnsignedInteger
;;;


IntervalType = INTERVAL >> IntervalQualifier
;;;


RowType = ROW >> RowTypeBody
;;;


RowTypeBody = (LeftParen >> (FieldDefinition%Comma) >> RightParen)
;;;


ReferenceType = (REF >> LeftParen >> ReferencedType >> RightParen >> !ScopeClause)
;;;


ScopeClause = SCOPE >> TableName
;;;


ReferencedType = PathResolvedUserDefinedTypeName
;;;


PathResolvedUserDefinedTypeName = UserDefinedTypeName
;;;


PathResolvedUserDefinedTypeName = UserDefinedTypeName
;;;


CollectionType = ArrayType
  | MultisetType
;;;


ArrayType = (DataType >> ARRAY >> !LeftBracketOrTrigraph >> UnsignedInteger >> RightBracketOrTrigraph)
;;;


MultisetType = DataType >> MULTISET
;;;


FieldDefinition = (FieldName >> DataType >> !ReferenceScopeCheck)
;;;


ValueExpressionPrimary = ParenthesizedValueExpression
  | NonparenthesizedValueExpressionPrimary
;;;


ParenthesizedValueExpression = LeftParen >> ValueExpression >> RightParen
;;;


NonparenthesizedValueExpressionPrimary = UnsignedValueSpecification
  | ColumnReference
  | SetFunctionSpecification
  | WindowFunction
  | ScalarSubquery
  | CaseExpression
  | CastSpecification
  | FieldReference
  | SubtypeTreatment
  | MethodInvocation
  | StaticMethodInvocation
  | NewSpecification
  | AttributeOrMethodReference
  | ReferenceResolution
  | CollectionValueConstructor
  | ArrayElementReference
  | MultisetElementReference
  | RoutineInvocation
  | NextValueExpression
;;;


ValueSpecification = Literal
  | GeneralValueSpecification
;;;


UnsignedValueSpecification = UnsignedLiteral
  | GeneralValueSpecification
;;;


GeneralValueSpecification = HostParameterSpecification
  | SQLParameterReference
  | DynamicParameterSpecification
  | EmbeddedVariableSpecification
  | CurrentCollationSpecification
  | CURRENT_DEFAULT_TRANSFORM_GROUP
  | CURRENT_PATH
  | CURRENT_ROLE
  | CURRENT_TRANSFORM_GROUP_FOR_TYPE >> PathResolvedUserDefinedTypeName
  | CURRENT_USER
  | SESSION_USER
  | SYSTEM_USER
  | USER
  | VALUE
;;;


SimpleValueSpecification = Literal
  | HostParameterName
  | SQLParameterReference
  | EmbeddedVariableName
;;;


TargetSpecification = HostParameterSpecification
  | SQLParameterReference
  | ColumnReference
  | TargetArrayElementSpecification
  | DynamicParameterSpecification
  | EmbeddedVariableSpecification
;;;


SimpleTargetSpecification = HostParameterSpecification
  | SQLParameterReference
  | ColumnReference
  | EmbeddedVariableName
;;;


HostParameterSpecification = (HostParameterName >> !IndicatorParameter)
;;;


DynamicParameterSpecification = QuestionMark
;;;


EmbeddedVariableSpecification = (EmbeddedVariableName >> !IndicatorVariable)
;;;


IndicatorVariable = !(INDICATOR >> EmbeddedVariableName)
;;;


IndicatorParameter = !(INDICATOR >> HostParameterName)
;;;


TargetArrayElementSpecification = TargetArrayReference >> LeftBracketOrTrigraph >> SimpleValueSpecification >> RightBracketOrTrigraph
;;;


TargetArrayReference = SQLParameterReference
  | ColumnReference
;;;


CurrentCollationSpecification = CURRENT_COLLATION >> LeftParen >> StringValueExpression >> RightParen
;;;


ContextuallyTypedValueSpecification = ImplicitlyTypedValueSpecification
  | DefaultSpecification
;;;


ImplicitlyTypedValueSpecification = NullSpecification
  | EmptySpecification
;;;


NullSpecification = NULL
;;;


EmptySpecification = ARRAY >> LeftBracketOrTrigraph >> RightBracketOrTrigraph
  | MULTISET >> LeftBracketOrTrigraph >> RightBracketOrTrigraph
;;;


DefaultSpecification = DEFAULT
;;;


IdentifierChain = ((Identifier%Period))
;;;


BasicIdentifierChain = IdentifierChain
;;;


ColumnReference = BasicIdentifierChain
  | MODULE >> Period >> QualifiedIdentifier >> Period >> ColumnName
;;;


SQLParameterReference = BasicIdentifierChain
;;;


SetFunctionSpecification = AggregateFunction
  | GroupingOperation
;;;


GroupingOperation = (GROUPING >> LeftParen >> (ColumnReference%Comma) >> RightParen)
;;;


WindowFunction = WindowFunctionType >> OVER >> WindowNameOrSpecification
;;;


WindowFunctionType = RankFunctionType >> LeftParen >> RightParen
  | ROW_NUMBER >> LeftParen >> RightParen
  | AggregateFunction
;;;


RankFunctionType = RANK
  | DENSE_RANK
  | PERCENT_RANK
  | CUME_DIST
;;;


WindowNameOrSpecification = WindowName
  | InLineWindowSpecification
;;;


InLineWindowSpecification = WindowSpecification
;;;


CaseExpression = CaseAbbreviation
  | CaseSpecification
;;;


CaseAbbreviation = NULLIF >> LeftParen >> ValueExpression >> Comma >> ValueExpression >> RightParen
  | (COALESCE >> LeftParen >> ValueExpression >> +Comma >> ValueExpression >> RightParen)
;;;


CaseSpecification = SimpleCase
  | SearchedCase
;;;


SimpleCase = (CASE >> CaseOperand >> +SimpleWhenClause >> !ElseClause >> END)
;;;


SearchedCase = (CASE >> +SearchedWhenClause >> !ElseClause >> END)
;;;


SimpleWhenClause = WHEN >> WhenOperand >> THEN >> Result
;;;


SearchedWhenClause = WHEN >> SearchCondition >> THEN >> Result
;;;


ElseClause = ELSE >> Result
;;;


CaseOperand = RowValuePredicand
  | OverlapsPredicatePart
;;;


WhenOperand = RowValuePredicand
  | ComparisonPredicatePart2
  | BetweenPredicatePart2
  | InPredicatePart2
  | CharacterLikePredicatePart2
  | OctetLikePredicatePart2
  | SimilarPredicatePart2
  | NullPredicatePart2
  | QuantifiedComparisonPredicatePart2
  | MatchPredicatePart2
  | OverlapsPredicatePart2
  | DistinctPredicatePart2
  | MemberPredicatePart2
  | SubmultisetPredicatePart2
  | SetPredicatePart2
  | TypePredicatePart2
;;;


Result = ResultExpression
  | NULL
;;;


ResultExpression = ValueExpression
;;;


CastSpecification = CAST >> LeftParen >> CastOperand >> AS >> CastTarget >> RightParen
;;;


CastOperand = ValueExpression
  | ImplicitlyTypedValueSpecification
;;;


CastTarget = DomainName
  | DataType
;;;


NextValueExpression = NEXT >> VALUE >> FOR >> SequenceGeneratorName
;;;


FieldReference = ValueExpressionPrimary >> Period >> FieldName
;;;


SubtypeTreatment = TREAT >> LeftParen >> SubtypeOperand >> AS >> TargetSubtype >> RightParen
;;;


SubtypeOperand = ValueExpression
;;;


TargetSubtype = PathResolvedUserDefinedTypeName
  | ReferenceType
;;;


MethodInvocation = DirectInvocation
  | GeneralizedInvocation
;;;


DirectInvocation = (ValueExpressionPrimary >> Period >> MethodName >> !SQLArgumentList)
;;;


GeneralizedInvocation = (LeftParen >> ValueExpressionPrimary >> AS >> DataType >> RightParen >> Period >> MethodName >> !SQLArgumentList)
;;;


MethodSelection = RoutineInvocation
;;;


ConstructorMethodSelection = RoutineInvocation
;;;


StaticMethodInvocation = (PathResolvedUserDefinedTypeName >> DoubleColon >> MethodName >> !SQLArgumentList)
;;;


StaticMethodSelection = RoutineInvocation
;;;


NewSpecification = NEW >> RoutineInvocation
;;;


NewInvocation = MethodInvocation
  | RoutineInvocation
;;;


AttributeOrMethodReference = (ValueExpressionPrimary >> DereferenceOperator >> QualifiedIdentifier >> !SQLArgumentList)
;;;


DereferenceOperator = RightArrow
;;;


DereferenceOperation = ReferenceValueExpression >> DereferenceOperator >> AttributeName
;;;


MethodReference = ValueExpressionPrimary >> DereferenceOperator >> MethodName >> SQLArgumentList
;;;


ReferenceResolution = DEREF >> LeftParen >> ReferenceValueExpression >> RightParen
;;;


ArrayElementReference = ArrayValueExpression >> LeftBracketOrTrigraph >> NumericValueExpression >> RightBracketOrTrigraph
;;;


MultisetElementReference = ELEMENT >> LeftParen >> MultsetValueExpression >> RightParen
;;;


ValueExpression = CommonValueExpression
  | BooleanValueExpression
  | RowValueExpression
;;;


CommonValueExpression = NumericValueExpression
  | StringValueExpression
  | DatetimeValueExpression
  | IntervalValueExpression
  | UserDefinedTypeValueExpression
  | ReferenceValueExpression
  | CollectionValueExpression
;;;


UserDefinedTypeValueExpression = ValueExpressionPrimary
;;;


ReferenceValueExpression = ValueExpressionPrimary
;;;


CollectionValueExpression = ArrayValueExpression
  | MultisetValueExpression
;;;


CollectionValueConstructor = ArrayValueConstructor
  | MultisetValueConstructor
;;;


NumericValueExpression = Term
  | NumericValueExpression >> PlusSign >> Term
  | NumericValueExpression >> MinusSign >> Term
;;;


Term = Factor
  | Term >> Asterisk >> Factor
  | Term >> Solidus >> Factor
;;;


Factor = !(Sign >> NumericPrimary)
;;;


NumericPrimary = ValueExpressionPrimary
  | NumericValueFunction
;;;


NumericValueFunction = PositionExpression
  | ExtractExpression
  | LengthExpression
  | CardinalityExpression
  | AbsoluteValueExpression
  | ModulusExpression
  | NaturalLogarithm
  | ExponentialFunction
  | PowerFunction
  | SquareRoot
  | FloorFunction
  | CeilingFunction
  | WidthBucketFunction
;;;


PositionExpression = StringPositionExpression
  | BlobPositionExpression
;;;


StringPositionExpression = (POSITION >> LeftParen >> StringValueExpression >> IN >> StringValueExpression >> !USING >> CharLengthUnits >> RightParen)
;;;


BlobPositionExpression = POSITION >> LeftParen >> BlobValueExpression >> IN >> BlobValueExpression >> RightParen
;;;


LengthExpression = CharLengthExpression
  | OctetLengthExpression
;;;


CharLengthExpression = (CHAR_LENGTH
  | CHARACTER_LENGTH >> LeftParen >> StringValueExpression >> !USING >> CharLengthUnits >> RightParen)
;;;


OctetLengthExpression = OCTET_LENGTH >> LeftParen >> StringValueExpression >> RightParen
;;;


ExtractExpression = EXTRACT >> LeftParen >> ExtractField >> FROM >> ExtractSource >> RightParen
;;;


ExtractField = PrimaryDatetimeField
  | TimeZoneField
;;;


TimeZoneField = TIMEZONE_HOUR
  | TIMEZONE_MINUTE
;;;


ExtractSource = DatetimeValueExpression
  | IntervalValueExpression
;;;


CardinalityExpression = CARDINALITY >> LeftParen >> CollectionValueExpression >> RightParen
;;;


AbsoluteValueExpression = ABS >> LeftParen >> NumericValueExpression >> RightParen
;;;


ModulusExpression = MOD >> LeftParen >> NumericValueExpressionDividend >> Comma >> NumericValueExpressionDivisor >> RightParen
;;;


NaturalLogarithm = LN >> LeftParen >> NumericValueExpression >> RightParen
;;;


ExponentialFunction = EXP >> LeftParen >> NumericValueExpression >> RightParen
;;;


PowerFunction = POWER >> LeftParen >> NumericValueExpressionBase >> Comma >> NumericValueExpressionExponent >> RightParen
;;;


NumericValueExpressionBase = NumericValueExpression
;;;


NumericValueExpressionExponent = NumericValueExpression
;;;


SquareRoot = SQRT >> LeftParen >> NumericValueExpression >> RightParen
;;;


FloorFunction = FLOOR >> LeftParen >> NumericValueExpression >> RightParen
;;;


CeilingFunction = (CEIL
  | CEILING >> LeftParen >> NumericValueExpression >> RightParen)
;;;


WidthBucketFunction = WIDTH_BUCKET >> LeftParen >> WidthBucketOperand >> Comma >> WidthBucketBound1 >> Comma >> WidthBucketBound2 >> Comma >> WidthBucketCount >> RightParen
;;;


WidthBucketOperand = NumericValueExpression
;;;


WidthBucketBound1 = NumericValueExpression
;;;


WidthBucketBound2 = NumericValueExpression
;;;


WidthBucketCount = NumericValueExpression
;;;


StringValueExpression = CharacterValueExpression
  | BlobValueExpression
;;;


CharacterValueExpression = Concatenation
  | CharacterFactor
;;;


Concatenation = CharacterValueExpression >> ConcatenationOperator >> CharacterFactor
;;;


CharacterFactor = (CharacterPrimary >> !CollateClause)
;;;


CharacterPrimary = ValueExpressionPrimary
  | StringValueFunction
;;;


BlobValueExpression = BlobConcatenation
  | BlobFactor
;;;


BlobFactor = BlobPrimary
;;;


BlobPrimary = ValueExpressionPrimary
  | StringValueFunction
;;;


BlobConcatenation = BlobValueExpression >> ConcatenationOperator >> BlobFactor
;;;


StringValueFunction = CharacterValueFunction
  | BlobValueFunction
;;;


CharacterValueFunction = CharacterSubstringFunction
  | RegularExpressionSubstringFunction
  | Fold
  | Transcoding
  | CharacterTransliteration
  | TrimFunction
  | CharacterOverlayFunction
  | NormalizeFunction
  | SpecificTypeMethod
;;;


CharacterSubstringFunction = (SUBSTRING >> LeftParen >> CharacterValueExpression >> FROM >> StartPosition >> !FOR >> StringLength >> !USING >> CharLengthUnits >> RightParen)
;;;


RegularExpressionSubstringFunction = SUBSTRING >> LeftParen >> CharacterValueExpression >> SIMILAR >> CharacterValueExpression >> ESCAPE >> EscapeCharacter >> RightParen
;;;


Fold = (UPPER
  | LOWER >> LeftParen >> CharacterValueExpression >> RightParen)
;;;


Transcoding = CONVERT >> LeftParen >> CharacterValueExpression >> USING >> TranscodingName >> RightParen
;;;


CharacterTransliteration = TRANSLATE >> LeftParen >> CharacterValueExpression >> USING >> TransliterationName >> RightParen
;;;


TrimFunction = TRIM >> LeftParen >> TrimOperands >> RightParen
;;;


TrimOperands = !(!(TrimSpecification >> !TrimCharacter >> FROM) >> TrimSource)
;;;


TrimSource = CharacterValueExpression
;;;


TrimSpecification = LEADING
  | TRAILING
  | BOTH
;;;


TrimCharacter = CharacterValueExpression
;;;


CharacterOverlayFunction = (OVERLAY >> LeftParen >> CharacterValueExpression >> PLACING >> CharacterValueExpression >> FROM >> StartPosition >> !FOR >> StringLength >> !USING >> CharLengthUnits >> RightParen)
;;;


NormalizeFunction = NORMALIZE >> LeftParen >> CharacterValueExpression >> RightParen
;;;


SpecificTypeMethod = UserDefinedTypeValueExpression >> Period >> SPECIFICTYPE
;;;


BlobValueFunction = BlobSubstringFunction
  | BlobTrimFunction
  | BlobOverlayFunction
;;;


BlobSubstringFunction = (SUBSTRING >> LeftParen >> BlobValueExpression >> FROM >> StartPosition >> !FOR >> StringLength >> RightParen)
;;;


BlobTrimFunction = TRIM >> LeftParen >> BlobTrimOperands >> RightParen
;;;


BlobTrimOperands = !(!(TrimSpecification >> !TrimOctet >> FROM) >> BlobTrimSource)
;;;


BlobTrimSource = BlobValueExpression
;;;


TrimOctet = BlobValueExpression
;;;


BlobOverlayFunction = (OVERLAY >> LeftParen >> BlobValueExpression >> PLACING >> BlobValueExpression >> FROM >> StartPosition >> !FOR >> StringLength >> RightParen)
;;;


StartPosition = NumericValueExpression
;;;


StringLength = NumericValueExpression
;;;


DatetimeValueExpression = DatetimeTerm
  | IntervalValueExpression >> PlusSign >> DatetimeTerm
  | DatetimeValueExpression >> PlusSign >> IntervalTerm
  | DatetimeValueExpression >> MinusSign >> IntervalTerm
;;;


DatetimeTerm = DatetimeFactor
;;;


DatetimeFactor = (DatetimePrimary >> !TimeZone)
;;;


DatetimePrimary = ValueExpressionPrimary
  | DatetimeValueFunction
;;;


TimeZone = AT >> TimeZoneSpecifier
;;;


TimeZoneSpecifier = LOCAL
  | TIME >> ZONE >> IntervalPrimary
;;;


DatetimeValueFunction = CurrentDateValueFunction
  | CurrentTimeValueFunction
  | CurrentTimestampValueFunction
  | CurrentLocalTimeValueFunction
  | CurrentLocalTimestampValueFunction
;;;


CurrentDateValueFunction = CURRENT_DATE
;;;


CurrentTimeValueFunction = (CURRENT_TIME >> !LeftParen >> TimePrecision >> RightParen)
;;;


CurrentLocalTimeValueFunction = (LOCALTIME >> !LeftParen >> TimePrecision >> RightParen)
;;;


CurrentTimestampValueFunction = (CURRENT_TIMESTAMP >> !LeftParen >> TimestampPrecision >> RightParen)
;;;


CurrentLocalTimestampValueFunction = (LOCALTIMESTAMP >> !LeftParen >> TimestampPrecision >> RightParen)
;;;


IntervalValueExpression = IntervalTerm
  | IntervalValueExpression1 >> PlusSign >> IntervalTerm1
  | IntervalValueExpression1 >> MinusSign >> IntervalTerm1
  | LeftParen >> DatetimeValueExpression >> MinusSign >> DatetimeTerm >> RightParen >> IntervalQualifier
;;;


IntervalTerm = IntervalFactor
  | IntervalTerm2 >> Asterisk >> Factor
  | IntervalTerm2 >> Solidus >> Factor
  | Term >> Asterisk >> IntervalFactor
;;;


IntervalFactor = !(Sign >> IntervalPrimary)
;;;


IntervalPrimary = (ValueExpressionPrimary >> !IntervalQualifier)
  | IntervalValueFunction
;;;


IntervalValueExpression1 = IntervalValueExpression
;;;


IntervalTerm1 = IntervalTerm
;;;


IntervalTerm2 = IntervalTerm
;;;


IntervalValueFunction = IntervalAbsoluteValueFunction
;;;


IntervalAbsoluteValueFunction = ABS >> LeftParen >> IntervalValueExpression >> RightParen
;;;


BooleanValueExpression = BooleanTerm
  | BooleanValueExpression >> OR >> BooleanTerm
;;;


BooleanTerm = BooleanFactor
  | BooleanTerm >> AND >> BooleanFactor
;;;


BooleanFactor = !(NOT >> BooleanTest)
;;;


BooleanTest = (BooleanPrimary >> !(IS >> !NOT >> TruthValue))
;;;


TruthValue = TRUE
  | FALSE
  | UNKNOWN
;;;


BooleanPrimary = Predicate
  | BooleanPredicand
;;;


BooleanPredicand = ParenthesizedBooleanValueExpression
  | NonparenthesizedValueExpressionPrimary
;;;


ParenthesizedBooleanValueExpression = LeftParen >> BooleanValueExpression >> RightParen
;;;


ArrayValueExpression = ArrayConcatenation
  | ArrayFactor
;;;


ArrayConcatenation = ArrayValueExpression1 >> ConcatenationOperator >> ArrayFactor
;;;


ArrayValueExpression1 = ArrayValueExpression
;;;


ArrayFactor = ValueExpressionPrimary
;;;


ArrayValueConstructor = ArrayValueConstructorByEnumeration
  | ArrayValueConstructorByQuery
;;;


ArrayValueConstructorByEnumeration = ARRAY >> LeftBracketOrTrigraph >> ArrayElementList >> RightBracketOrTrigraph
;;;


ArrayElementList = ((ArrayElement%Comma))
;;;


ArrayElement = ValueExpression
;;;


ArrayValueConstructorByQuery = (ARRAY >> LeftParen >> QueryExpression >> !OrderByClause >> RightParen)
;;;


MultisetValueExpression = MultisetTerm
  | (MultisetValueExpression >> MULTISET >> UNION >> !ALL
  | DISTINCT >> MultisetTerm)
  | (MultisetValueExpression >> MULTISET >> EXCEPT >> !ALL
  | DISTINCT >> MultisetTerm)
;;;


MultisetTerm = MultisetPrimary
  | (MultisetTerm >> MULTISET >> INTERSECT >> !ALL
  | DISTINCT >> MultisetPrimary)
;;;


MultisetPrimary = MultisetValueFunction
  | ValueExpressionPrimary
;;;


MultisetValueFunction = MultisetSetFunction
;;;


MultisetSetFunction = SET >> LeftParen >> MultisetValueExpression >> RightParen
;;;


MultisetValueConstructor = MultisetValueConstructorByEnumeration
  | MultisetValueConstructorByQuery
  | TableValueConstructorByQuery
;;;


MultisetValueConstructorByEnumeration = MULTISET >> LeftBracketOrTrigraph >> MultisetElementList >> RightBracketOrTrigraph
;;;


MultisetElementList = (MultisetElement >> !(Comma >> MultisetElement))
;;;


MultisetElement = ValueExpression
;;;


MultisetValueConstructorByQuery = MULTISET >> LeftParen >> QueryExpression >> RightParen
;;;


TableValueConstructorByQuery = TABLE >> LeftParen >> QueryExpression >> RightParen >> Specify >> A >> Value >> Or >> List >> Of >> Values >> To >> Be >> Constructed >> Into >> A >> Row >> Or >> Partial >> Row.
;;;


RowValueConstructor = CommonValueExpression
  | BooleanValueExpression
  | ExplicitRowValueConstructor
;;;


ExplicitRowValueConstructor = LeftParen >> RowValueConstructorElement >> Comma >> RowValueConstructorElementList >> RightParen
  | ROW >> LeftParen >> RowValueConstructorElementList >> RightParen
  | RowSubquery
;;;


RowValueConstructorElementList = ((RowValueConstructorElement%Comma))
;;;


RowValueConstructorElement = ValueExpression
;;;


ContextuallyTypedRowValueConstructor = CommonValueExpression
  | BooleanValueExpression
  | ContextuallyTypedValueSpecification
  | LeftParen >> ContextuallyTypedRowValueConstructorElement >> Comma >> ContextuallyTypedRowValueConstructorElementList >> RightParen
  | ROW >> LeftParen >> ContextuallyTypedRowValueConstructorElementList >> RightParen
;;;


ContextuallyTypedRowValueConstructorElementList = ((ContextuallyTypedRowValueConstructorElement%Comma))
;;;


ContextuallyTypedRowValueConstructorElement = ValueExpression
  | ContextuallyTypedValueSpecification
;;;


RowValueConstructorPredicand = CommonValueExpression
  | BooleanPredicand
  | ExplicitRowValueConstructor
;;;


RowValueExpression = RowValueSpecialCase
  | ExplicitRowValueConstructor
;;;


TableRowValueExpression = RowValueSpecialCase
  | RowValueConstructor
;;;


ContextuallyTypedRowValueExpression = RowValueSpecialCase
  | ContextuallyTypedRowValueConstructor
;;;


RowValuePredicand = RowValueSpecialCase
  | RowValueConstructorPredicand
;;;


RowValueSpecialCase = NonparenthesizedValueExpressionPrimary
;;;


TableValueConstructor = VALUES >> RowValueExpressionList
;;;


RowValueExpressionList = ((TableRowValueExpression%Comma))
;;;


ContextuallyTypedTableValueConstructor = VALUES >> ContextuallyTypedRowValueExpressionList
;;;


ContextuallyTypedRowValueExpressionList = ((ContextuallyTypedRowValueExpression%Comma))
;;;


TableExpression = (FromClause >> !WhereClause >> !GroupByClause >> !HavingClause >> !WindowClause)
;;;


FromClause = FROM >> TableReferenceList
;;;


TableReferenceList = ((TableReference%Comma))
;;;


TableReference = (TablePrimaryOrJoinedTable >> !SampleClause)
;;;


TablePrimaryOrJoinedTable = TablePrimary
  | JoinedTable
;;;


SampleClause = (TABLESAMPLE >> SampleMethod >> LeftParen >> SamplePercentage >> RightParen >> !RepeatableClause)
;;;


SampleMethod = BERNOULLI
  | SYSTEM
;;;


RepeatableClause = REPEATABLE >> LeftParen >> RepeatArgument >> RightParen
;;;


SamplePercentage = NumericValueExpression
;;;


RepeatArgument = NumericValueExpression
;;;


TablePrimary = (TableOrQueryName >> !!(AS >> CorrelationName >> !LeftParen >> DerivedColumnList >> RightParen))
  | (DerivedTable >> !AS >> CorrelationName >> !LeftParen >> DerivedColumnList >> RightParen)
  | (LateralDerivedTable >> !AS >> CorrelationName >> !LeftParen >> DerivedColumnList >> RightParen)
  | (CollectionDerivedTable >> !AS >> CorrelationName >> !LeftParen >> DerivedColumnList >> RightParen)
  | (TableFunctionDerivedTable >> !AS >> CorrelationName >> !LeftParen >> DerivedColumnList >> RightParen)
  | (OnlySpec >> !!(AS >> CorrelationName >> !LeftParen >> DerivedColumnList >> RightParen))
  | LeftParen >> JoinedTable >> RightParen
;;;


OnlySpec = ONLY >> LeftParen >> TableOrQueryName >> RightParen
;;;


LateralDerivedTable = LATERAL >> TableSubquery
;;;


CollectionDerivedTable = (UNNEST >> LeftParen >> CollectionValueExpression >> RightParen >> !WITH >> ORDINALITY)
;;;


TableFunctionDerivedTable = TABLE >> LeftParen >> CollectionValueExpression >> RightParen
;;;


DerivedTable = TableSubquery
;;;


TableOrQueryName = TableName
  | QueryName
;;;


DerivedColumnList = ColumnNameList
;;;


ColumnNameList = ((ColumnName%Comma))
;;;


JoinedTable = CrossJoin
  | QualifiedJoin
  | NaturalJoin
  | UnionJoin
;;;


CrossJoin = TableReference >> CROSS >> JOIN >> TablePrimary
;;;


QualifiedJoin = (TableReference >> !JoinType >> JOIN >> TableReference >> JoinSpecification)
;;;


NaturalJoin = (TableReference >> NATURAL >> !JoinType >> JOIN >> TablePrimary)
;;;


UnionJoin = TableReference >> UNION >> JOIN >> TablePrimary
;;;


JoinSpecification = JoinCondition
  | NamedColumnsJoin
;;;


JoinCondition = ON >> SearchCondition
;;;


NamedColumnsJoin = USING >> LeftParen >> JoinColumnList >> RightParen
;;;


JoinType = INNER
  | (OuterJoinType >> !OUTER)
;;;


OuterJoinType = LEFT
  | RIGHT
  | FULL
;;;


JoinColumnList = ColumnNameList
;;;


WhereClause = WHERE >> SearchCondition
;;;


GroupByClause = (GROUP >> BY >> !SetQuantifier >> GroupingElementList)
;;;


GroupingElementList = ((GroupingElement%Comma))
;;;


GroupingElement = OrdinaryGroupingSet
  | RollupList
  | CubeList
  | GroupingSetsSpecification
  | EmptyGroupingSet
;;;


OrdinaryGroupingSet = GroupingColumnReference
  | LeftParen >> GroupingColumnReferenceList >> RightParen
;;;


GroupingColumnReference = (ColumnReference >> !CollateClause)
;;;


GroupingColumnReferenceList = ((GroupingColumnReference%Comma))
;;;


RollupList = ROLLUP >> LeftParen >> OrdinaryGroupingSetList >> RightParen
;;;


OrdinaryGroupingSetList = ((OrdinaryGroupingSet%Comma))
;;;


CubeList = CUBE >> LeftParen >> OrdinaryGroupingSetList >> RightParen
;;;


GroupingSetsSpecification = GROUPING >> SETS >> LeftParen >> GroupingSetList >> RightParen
;;;


GroupingSetList = ((GroupingSet%Comma))
;;;


GroupingSet = OrdinaryGroupingSet
  | RollupList
  | CubeList
  | GroupingSetsSpecification
  | EmptyGroupingSet
;;;


EmptyGroupingSet = LeftParen >> RightParen
;;;


HavingClause = HAVING >> SearchCondition
;;;


WindowClause = WINDOW >> WindowDefinitionList
;;;


WindowDefinitionList = ((WindowDefinition%Comma))
;;;


WindowDefinition = NewWindowName >> AS >> WindowSpecification
;;;


NewWindowName = WindowName
;;;


WindowSpecification = LeftParen >> WindowSpecificationDetails >> RightParen
;;;


WindowSpecificationDetails = !(ExistingWindowName >> !WindowPartitionClause >> !WindowOrderClause >> !WindowFrameClause)
;;;


ExistingWindowName = WindowName
;;;


WindowPartitionClause = PARTITION >> BY >> WindowPartitionColumnReferenceList
;;;


WindowPartitionColumnReferenceList = ((WindowPartitionColumnReference%Comma))
;;;


WindowPartitionColumnReference = (ColumnReference >> !CollateClause)
;;;


WindowOrderClause = ORDER >> BY >> SortSpecificationList
;;;


WindowFrameClause = (WindowFrameUnits >> WindowFrameExtent >> !WindowFrameExclusion)
;;;


WindowFrameUnits = ROWS
  | RANGE
;;;


WindowFrameExtent = WindowFrameStart
  | WindowFrameBetween
;;;


WindowFrameStart = UNBOUNDED >> PRECEDING
  | WindowFramePreceding
  | CURRENT >> ROW
;;;


WindowFramePreceding = UnsignedValueSpecification >> PRECEDING
;;;


WindowFrameBetween = BETWEEN >> WindowFrameBound1 >> AND >> WindowFrameBound2
;;;


WindowFrameBound1 = WindowFrameBound
;;;


WindowFrameBound2 = WindowFrameBound
;;;


WindowFrameBound = WindowFrameStart
  | UNBOUNDED >> FOLLOWING
  | WindowFrameFollowing
;;;


WindowFrameFollowing = UnsignedValueSpecification >> FOLLOWING
;;;


WindowFrameExclusion = EXCLUDE >> CURRENT >> ROW
  | EXCLUDE >> GROUP
  | EXCLUDE >> TIES
  | EXCLUDE >> NO >> OTHERS
;;;


QuerySpecification = (SELECT >> !SetQuantifier >> SelectList >> TableExpression)
;;;


SelectList = Asterisk
  | ((SelectSublist%Comma))
;;;


SelectSublist = DerivedColumn
  | QualifiedAsterisk
;;;


QualifiedAsterisk = AsteriskedIdentifierChain >> Period >> Asterisk
  | AllFieldsReference
;;;


AsteriskedIdentifierChain = ((AsteriskedIdentifier%Period))
;;;


AsteriskedIdentifier = Identifier
;;;


DerivedColumn = (ValueExpression >> !AsClause)
;;;


AsClause = !(AS >> ColumnName)
;;;


AllFieldsReference = (ValueExpressionPrimary >> Period >> Asterisk >> !AS >> LeftParen >> AllFieldsColumnNameList >> RightParen)
;;;


AllFieldsColumnNameList = ColumnNameList
;;;


QueryExpression = !(WithClause >> QueryExpressionBody)
;;;


WithClause = (WITH >> !RECURSIVE >> WithList)
;;;


WithList = ((WithListElement%Comma))
;;;


WithListElement = (QueryName >> !LeftParen >> WithColumnList >> RightParen >> AS >> LeftParen >> QueryExpression >> RightParen >> !SearchOrCycleClause)
;;;


WithColumnList = ColumnNameList
;;;


QueryExpressionBody = NonJoinQueryExpression
  | JoinedTable
;;;


NonJoinQueryExpression = NonJoinQueryTerm
  | (QueryExpressionBody >> UNION >> !ALL
  | DISTINCT >> !CorrespondingSpec >> QueryTerm)
  | (QueryExpressionBody >> EXCEPT >> !ALL
  | DISTINCT >> !CorrespondingSpec >> QueryTerm)
;;;


QueryTerm = NonJoinQueryTerm
  | JoinedTable
;;;


NonJoinQueryTerm = NonJoinQueryPrimary
  | (QueryTerm >> INTERSECT >> !ALL
  | DISTINCT >> !CorrespondingSpec >> QueryPrimary)
;;;


QueryPrimary = NonJoinQueryPrimary
  | JoinedTable
;;;


NonJoinQueryPrimary = SimpleTable
  | LeftParen >> NonJoinQueryExpression >> RightParen
;;;


SimpleTable = QuerySpecification
  | TableValueConstructor
  | ExplicitTable
;;;


ExplicitTable = TABLE >> TableOrQueryName
;;;


CorrespondingSpec = (CORRESPONDING >> !BY >> LeftParen >> CorrespondingColumnList >> RightParen)
;;;


CorrespondingColumnList = ColumnNameList
;;;


SearchOrCycleClause = SearchClause
  | CycleClause
  | SearchClause >> CycleClause
;;;


SearchClause = SEARCH >> RecursiveSearchOrder >> SET >> SequenceColumn
;;;


RecursiveSearchOrder = DEPTH >> FIRST >> BY >> SortSpecificationList
  | BREADTH >> FIRST >> BY >> SortSpecificationList
;;;


SequenceColumn = ColumnName
;;;


CycleClause = CYCLE >> CycleColumnList >> SET >> CycleMarkColumn >> TO >> CycleMarkValue >> DEFAULT >> NonCycleMarkValue >> USING >> PathColumn
;;;


CycleColumnList = ((CycleColumn%Comma))
;;;


CycleColumn = ColumnName
;;;


CycleMarkColumn = ColumnName
;;;


PathColumn = ColumnName
;;;


CycleMarkValue = ValueExpression
;;;


NonCycleMarkValue = ValueExpression
;;;


ScalarSubquery = Subquery
;;;


RowSubquery = Subquery
;;;


TableSubquery = Subquery
;;;


Subquery = LeftParen >> QueryExpression >> RightParen
;;;


Predicate = ComparisonPredicate
  | BetweenPredicate
  | InPredicate
  | LikePredicate
  | SimilarPredicate
  | NullPredicate
  | QuantifiedComparisonPredicate
  | ExistsPredicate
  | UniquePredicate
  | NormalizedPredicate
  | MatchPredicate
  | OverlapsPredicate
  | DistinctPredicate
  | MemberPredicate
  | SubmultisetPredicate
  | SetPredicate
  | TypePredicate
;;;


ComparisonPredicate = RowValuePredicand >> ComparisonPredicatePart2
;;;


ComparisonPredicatePart2 = CompOp >> RowValuePredicand
;;;


CompOp = EqualsOperator
  | NotEqualsOperator
  | LessThanOperator
  | GreaterThanOperator
  | LessThanOrEqualsOperator
  | GreaterThanOrEqualsOperator
;;;


BetweenPredicate = RowValuePredicand >> BetweenPredicatePart2
;;;


BetweenPredicatePart2 = !(NOT >> BETWEEN >> !ASYMMETRIC
  | SYMMETRIC >> RowValuePredicand >> AND >> RowValuePredicand)
;;;


InPredicate = RowValuePredicand >> InPredicatePart2
;;;


InPredicatePart2 = !(NOT >> IN >> InPredicateValue)
;;;


InPredicateValue = TableSubquery
  | LeftParen >> InValueList >> RightParen
;;;


InValueList = ((RowValueExpression%Comma))
;;;


LikePredicate = CharacterLikePredicate
  | OctetLikePredicate
;;;


CharacterLikePredicate = RowValuePredicand >> CharacterLikePredicatePart2
;;;


CharacterLikePredicatePart2 = !(NOT >> LIKE >> CharacterPattern >> !ESCAPE >> EscapeCharacter)
;;;


CharacterPattern = CharacterValueExpression
;;;


EscapeCharacter = CharacterValueExpression
;;;


OctetLikePredicate = RowValuePredicand >> OctetLikePredicatePart2
;;;


OctetLikePredicatePart2 = !(NOT >> LIKE >> OctetPattern >> !ESCAPE >> EscapeOctet)
;;;


OctetPattern = BlobValueExpression
;;;


EscapeOctet = BlobValueExpression
;;;


SimilarPredicate = RowValuePredicand >> SimilarPredicatePart2
;;;


SimilarPredicatePart2 = !(NOT >> SIMILAR >> TO >> SimilarPattern >> !ESCAPE >> EscapeCharacter)
;;;


SimilarPattern = CharacterValueExpression
;;;


RegularExpression = RegularTerm
  | RegularExpression >> VerticalBar >> RegularTerm
;;;


RegularTerm = RegularFactor
  | RegularTerm >> RegularFactor
;;;


RegularFactor = RegularPrimary
  | RegularPrimary >> Asterisk
  | RegularPrimary >> PlusSign
  | RegularPrimary >> QuestionMark
  | RegularPrimary >> RepeatFactor
;;;


RepeatFactor = (LeftBrace >> LowValue >> !UpperLimit >> RightBrace)
;;;


UpperLimit = (Comma >> !HighValue)
;;;


LowValue = UnsignedInteger
;;;


HighValue = UnsignedInteger
;;;


RegularPrimary = CharacterSpecifier
  | Percent
  | RegularCharacterSet
  | LeftParen >> RegularExpression >> RightParen
;;;


CharacterSpecifier = NonEscapedCharacter
  | EscapedCharacter
;;;


NonEscapedCharacter = !!See >> The >> Syntax >> Rules
;;;


EscapedCharacter = !!See >> The >> Syntax >> Rules
;;;


RegularCharacterSet = Underscore
  | (LeftBracket >> +CharacterEnumeration >> RightBracket)
  | (LeftBracket >> Circumflex >> +CharacterEnumeration >> RightBracket)
  | (LeftBracket >> +CharacterEnumerationInclude >> Circumflex >> +CharacterEnumerationExclude >> RightBracket)
;;;


CharacterEnumerationInclude = CharacterEnumeration
;;;


CharacterEnumerationExclude = CharacterEnumeration
;;;


CharacterEnumeration = CharacterSpecifier
  | CharacterSpecifier >> MinusSign >> CharacterSpecifier
  | LeftBracket >> Colon >> RegularCharacterSetIdentifier >> Colon >> RightBracket
;;;


RegularCharacterSetIdentifier = Identifier
;;;


NullPredicate = RowValuePredicand >> NullPredicatePart2
;;;


NullPredicatePart2 = (IS >> !NOT >> NULL)
;;;


QuantifiedComparisonPredicate = RowValuePredicand >> QuantifiedComparisonPredicatePart2
;;;


QuantifiedComparisonPredicatePart2 = CompOp >> Quantifier >> TableSubquery
;;;


Quantifier = All
  | Some
;;;


All = ALL
;;;


Some = SOME
  | ANY
;;;


ExistsPredicate = EXISTS >> TableSubquery
;;;


UniquePredicate = UNIQUE >> TableSubquery
;;;


NormalizedPredicate = (StringValueExpression >> IS >> !NOT >> NORMALIZED)
;;;


MatchPredicate = RowValuePredicand >> MatchPredicatePart2
;;;


MatchPredicatePart2 = (MATCH >> !UNIQUE >> !SIMPLE
  | PARTIAL
  | FULL >> TableSubquery)
;;;


OverlapsPredicate = OverlapsPredicatePart1 >> OverlapsPredicatePart2
;;;


OverlapsPredicatePart1 = RowValuePredicand1
;;;


OverlapsPredicatePart2 = OVERLAPS >> RowValuePredicand2
;;;


RowValuePredicand1 = RowValuePredicand
;;;


RowValuePredicand2 = RowValuePredicand
;;;


DistinctPredicate = RowValuePredicand3 >> DistinctPredicatePart2
;;;


DistinctPredicatePart2 = IS >> DISTINCT >> FROM >> RowValuePredicand4
;;;


RowValuePredicand3 = RowValuePredicand
;;;


RowValuePredicand4 = RowValuePredicand
;;;


MemberPredicate = RowValuePredicand >> MemberPredicatePart2
;;;


MemberPredicatePart2 = !(NOT >> MEMBER >> !OF >> MultisetValueExpression)
;;;


SubmultisetPredicate = RowValuePredicand >> SubmultisetPredicatePart2
;;;


SubmultisetPredicatePart2 = !(NOT >> SUBMULTISET >> !OF >> MultisetValueExpression)
;;;


SetPredicate = RowValuePredicand >> SetPredicatePart2
;;;


SetPredicatePart2 = (IS >> !NOT >> A >> SET)
;;;


TypePredicate = RowValuePredicand >> TypePredicatePart2
;;;


TypePredicatePart2 = (IS >> !NOT >> OF >> LeftParen >> TypeList >> RightParen)
;;;


TypeList = ((UserDefinedTypeSpecification%Comma))
;;;


UserDefinedTypeSpecification = InclusiveUserDefinedTypeSpecification
  | ExclusiveUserDefinedTypeSpecification
;;;


InclusiveUserDefinedTypeSpecification = PathResolvedUserDefinedTypeName
;;;


ExclusiveUserDefinedTypeSpecification = ONLY >> PathResolvedUserDefinedTypeName
;;;


SearchCondition = BooleanValueExpression
;;;


IntervalQualifier = StartField >> TO >> EndField
  | SingleDatetimeField
;;;


StartField = (NonSecondPrimaryDatetimeField >> !LeftParen >> IntervalLeadingFieldPrecision >> RightParen)
;;;


EndField = NonSecondPrimaryDatetimeField
  | (SECOND >> !LeftParen >> IntervalFractionalSecondsPrecision >> RightParen)
;;;


SingleDatetimeField = (NonSecondPrimaryDatetimeField >> !LeftParen >> IntervalLeadingFieldPrecision >> RightParen)
  | (SECOND >> !(LeftParen >> IntervalLeadingFieldPrecision >> !Comma >> IntervalFractionalSecondsPrecision >> RightParen))
;;;


PrimaryDatetimeField = NonSecondPrimaryDatetimeField
  | SECOND
;;;


NonSecondPrimaryDatetimeField = YEAR
  | MONTH
  | DAY
  | HOUR
  | MINUTE
;;;


IntervalFractionalSecondsPrecision = UnsignedInteger
;;;


IntervalLeadingFieldPrecision = UnsignedInteger
;;;


LanguageClause = LANGUAGE >> LanguageName
;;;


LanguageName = ADA
  | C
  | COBOL
  | FORTRAN
  | MUMPS
  | PASCAL
  | PLI
  | SQL
;;;


PathSpecification = PATH >> SchemaNameList
;;;


SchemaNameList = ((SchemaName%Comma))
;;;


RoutineInvocation = RoutineName >> SQLArgumentList
;;;


RoutineName = !(SchemaName >> Period >> QualifiedIdentifier)
;;;


SQLArgumentList = (LeftParen >> !((SQLArgument%Comma)) >> RightParen)
;;;


SQLArgument = ValueExpression
  | GeneralizedExpression
  | TargetSpecification
;;;


GeneralizedExpression = ValueExpression >> AS >> PathResolvedUserDefinedTypeName
;;;


CharacterSetSpecification = StandardCharacterSetName
  | ImplementationDefinedCharacterSetName
  | UserDefinedCharacterSetName
;;;


StandardCharacterSetName = CharacterSetName
;;;


ImplementationDefinedCharacterSetName = CharacterSetName
;;;


UserDefinedCharacterSetName = CharacterSetName
;;;


SpecificRoutineDesignator = SPECIFIC >> RoutineType >> SpecificName
  | (RoutineType >> MemberName >> !FOR >> SchemaResolvedUserDefinedTypeName)
;;;


RoutineType = ROUTINE
  | FUNCTION
  | PROCEDURE
  | !(INSTANCE
  | STATIC
  | CONSTRUCTOR >> METHOD)
;;;


MemberName = (MemberNameAlternatives >> !DataTypeList)
;;;


MemberNameAlternatives = SchemaQualifiedRoutineName
  | MethodName
;;;


DataTypeList = (LeftParen >> !((DataType%Comma)) >> RightParen)
;;;


CollateClause = COLLATE >> CollationName
;;;


ConstraintNameDefinition = CONSTRAINT >> ConstraintName
;;;


ConstraintCharacteristics = (ConstraintCheckTime >> !!(NOT >> DEFERRABLE))
  | !(NOT >> DEFERRABLE >> !ConstraintCheckTime)
;;;


ConstraintCheckTime = INITIALLY >> DEFERRED
  | INITIALLY >> IMMEDIATE
;;;


AggregateFunction = (COUNT >> LeftParen >> Asterisk >> RightParen >> !FilterClause)
  | (GeneralSetFunction >> !FilterClause)
  | (BinarySetFunction >> !FilterClause)
  | (OrderedSetFunction >> !FilterClause)
;;;


GeneralSetFunction = (SetFunctionType >> LeftParen >> !SetQuantifier >> ValueExpression >> RightParen)
;;;


SetFunctionType = ComputationalOperation
;;;


ComputationalOperation = AVG
  | MAX
  | MIN
  | SUM
  | EVERY
  | ANY
  | SOME
  | COUNT
  | STDDEV_POP
  | STDDEV_SAMP
  | VAR_SAMP
  | VAR_POP
  | COLLECT
  | FUSION
  | INTERSECTION
;;;


SetQuantifier = DISTINCT
  | ALL
;;;


FilterClause = FILTER >> LeftParen >> WHERE >> SearchCondition >> RightParen
;;;


BinarySetFunction = BinarySetFunctionType >> LeftParen >> DependentVariableExpression >> Comma >> IndependentVariableExpression >> RightParen
;;;


BinarySetFunctionType = COVAR_POP
  | COVAR_SAMP
  | CORR
  | REGR_SLOPE
  | REGR_INTERCEPT
  | REGR_COUNT
  | REGR_R2
  | REGR_AVGX
  | REGR_AVGY
  | REGR_SXX
  | REGR_SYY
  | REGR_SXY
;;;


DependentVariableExpression = NumericValueExpression
;;;


IndependentVariableExpression = NumericValueExpression
;;;


OrderedSetFunction = HypotheticalSetFunction
  | InverseDistributionFunction
;;;


HypotheticalSetFunction = RankFunctionType >> LeftParen >> HypotheticalSetFunctionValueExpressionList >> RightParen >> WithinGroupSpecification
;;;


WithinGroupSpecification = WITHIN >> GROUP >> LeftParen >> ORDER >> BY >> SortSpecificationList >> RightParen
;;;


HypotheticalSetFunctionValueExpressionList = ((ValueExpression%Comma))
;;;


InverseDistributionFunction = InverseDistributionFunctionType >> LeftParen >> InverseDistributionFunctionArgument >> RightParen >> WithinGroupSpecification
;;;


InverseDistributionFunctionArgument = NumericValueExpression
;;;


InverseDistributionFunctionType = PERCENTILE_CONT
  | PERCENTILE_DISC
;;;


SortSpecificationList = ((SortSpecification%Comma))
;;;


SortSpecification = (SortKey >> !OrderingSpecification >> !NullOrdering)
;;;


SortKey = ValueExpression
;;;


OrderingSpecification = ASC
  | DESC
;;;


NullOrdering = NULLS >> FIRST
  | NULLS >> LAST
;;;


SchemaDefinition = (CREATE >> SCHEMA >> SchemaNameClause >> !SchemaCharacterSetOrPath >> *SchemaElement)
;;;


SchemaCharacterSetOrPath = SchemaCharacterSetSpecification
  | SchemaPathSpecification
  | SchemaCharacterSetSpecification >> SchemaPathSpecification
  | SchemaPathSpecification >> SchemaCharacterSetSpecification
;;;


SchemaNameClause = SchemaName
  | AUTHORIZATION >> SchemaAuthorizationIdentifier
  | SchemaName >> AUTHORIZATION >> SchemaAuthorizationIdentifier
;;;


SchemaAuthorizationIdentifier = AuthorizationIdentifier
;;;


SchemaCharacterSetSpecification = DEFAULT >> CHARACTER >> SET >> CharacterSetSpecification
;;;


SchemaPathSpecification = PathSpecification
;;;


SchemaElement = TableDefinition
  | ViewDefinition
  | DomainDefinition
  | CharacterSetDefinition
  | CollationDefinition
  | TransliterationDefinition
  | AssertionDefinition
  | TriggerDefinition
  | UserDefinedTypeDefinition
  | UserDefinedCastDefinition
  | UserDefinedOrderingDefinition
  | TransformDefinition
  | SchemaRoutine
  | SequenceGeneratorDefinition
  | GrantStatement
  | RoleDefinition
;;;


DropSchemaStatement = DROP >> SCHEMA >> SchemaName >> DropBehavior
;;;


DropBehavior = CASCADE
  | RESTRICT
;;;


TableDefinition = (CREATE >> !TableScope >> TABLE >> TableName >> TableContentsSource >> !ON >> COMMIT >> TableCommitAction >> ROWS)
;;;


TableContentsSource = TableElementList
  | (OF >> PathResolvedUserDefinedTypeName >> !SubtableClause >> !TableElementList)
  | AsSubqueryClause
;;;


TableScope = GlobalOrLocal >> TEMPORARY
;;;


GlobalOrLocal = GLOBAL
  | LOCAL
;;;


TableCommitAction = PRESERVE
  | DELETE
;;;


TableElementList = (LeftParen >> (TableElement%Comma) >> RightParen)
;;;


TableElement = ColumnDefinition
  | TableConstraintDefinition
  | LikeClause
  | SelfReferencingColumnSpecification
  | ColumnOptions
;;;


SelfReferencingColumnSpecification = REF >> IS >> SelfReferencingColumnName >> ReferenceGeneration
;;;


ReferenceGeneration = SYSTEM >> GENERATED
  | USER >> GENERATED
  | DERIVED
;;;


SelfReferencingColumnName = ColumnName
;;;


ColumnOptions = ColumnName >> WITH >> OPTIONS >> ColumnOptionList
;;;


ColumnOptionList = !(ScopeClause >> !DefaultClause >> *ColumnConstraintDefinition)
;;;


SubtableClause = UNDER >> SupertableClause
;;;


SupertableClause = SupertableName
;;;


SupertableName = TableName
;;;


LikeClause = (LIKE >> TableName >> !LikeOptions)
;;;


LikeOptions = IdentityOption
  | ColumnDefaultOption
;;;


IdentityOption = INCLUDING >> IDENTITY
  | EXCLUDING >> IDENTITY
;;;


ColumnDefaultOption = INCLUDING >> DEFAULTS
  | EXCLUDING >> DEFAULTS
;;;


AsSubqueryClause = !(LeftParen >> ColumnNameList >> RightParen >> AS >> Subquery >> WithOrWithoutData)
;;;


WithOrWithoutData = WITH >> NO >> DATA
  | WITH >> DATA
;;;


ColumnDefinition = (ColumnName >> !DataType
  | DomainName >> !ReferenceScopeCheck >> !DefaultClause
  | IdentityColumnSpecification
  | GenerationClause >> *ColumnConstraintDefinition >> !CollateClause)
;;;


ColumnConstraintDefinition = !(ConstraintNameDefinition >> ColumnConstraint >> !ConstraintCharacteristics)
;;;


ColumnConstraint = NOT >> NULL
  | UniqueSpecification
  | ReferencesSpecification
  | CheckConstraintDefinition
;;;


ReferenceScopeCheck = (REFERENCES >> ARE >> !NOT >> CHECKED >> !ON >> DELETE >> ReferenceScopeCheckAction)
;;;


ReferenceScopeCheckAction = ReferentialAction
;;;


IdentityColumnSpecification = (GENERATED >> ALWAYS
  | BY >> DEFAULT >> AS >> IDENTITY >> !LeftParen >> CommonSequenceGeneratorOptions >> RightParen)
;;;


GenerationClause = GenerationRule >> AS >> GenerationExpression
;;;


GenerationRule = GENERATED >> ALWAYS
;;;


GenerationExpression = LeftParen >> ValueExpression >> RightParen
;;;


DefaultClause = DEFAULT >> DefaultOption
;;;


DefaultOption = Literal
  | DatetimeValueFunction
  | USER
  | CURRENT_USER
  | CURRENT_ROLE
  | SESSION_USER
  | SYSTEM_USER
  | CURRENT_PATH
  | ImplicitlyTypedValueSpecification
;;;


TableConstraintDefinition = !(ConstraintNameDefinition >> TableConstraint >> !ConstraintCharacteristics)
;;;


TableConstraint = UniqueConstraintDefinition
  | ReferentialConstraintDefinition
  | CheckConstraintDefinition
;;;


UniqueConstraintDefinition = UniqueSpecification >> LeftParen >> UniqueColumnList >> RightParen
  | (UNIQUE >> VALUE)
;;;


UniqueSpecification = UNIQUE
  | PRIMARY >> KEY
;;;


UniqueColumnList = ColumnNameList
;;;


ReferentialConstraintDefinition = FOREIGN >> KEY >> LeftParen >> ReferencingColumns >> RightParen >> ReferencesSpecification
;;;


ReferencesSpecification = (REFERENCES >> ReferencedTableAndColumns >> !MATCH >> MatchType >> !ReferentialTriggeredAction)
;;;


MatchType = FULL
  | PARTIAL
  | SIMPLE
;;;


ReferencingColumns = ReferenceColumnList
;;;


ReferencedTableAndColumns = (TableName >> !LeftParen >> ReferenceColumnList >> RightParen)
;;;


ReferenceColumnList = ColumnNameList
;;;


ReferentialTriggeredAction = (UpdateRule >> !DeleteRule)
  | (DeleteRule >> !UpdateRule)
;;;


UpdateRule = ON >> UPDATE >> ReferentialAction
;;;


DeleteRule = ON >> DELETE >> ReferentialAction
;;;


ReferentialAction = CASCADE
  | SET >> NULL
  | SET >> DEFAULT
  | RESTRICT
  | NO >> ACTION
;;;


CheckConstraintDefinition = CHECK >> LeftParen >> SearchCondition >> RightParen
;;;


AlterTableStatement = ALTER >> TABLE >> TableName >> AlterTableAction
;;;


AlterTableAction = AddColumnDefinition
  | AlterColumnDefinition
  | DropColumnDefinition
  | AddTableConstraintDefinition
  | DropTableConstraintDefinition
;;;


AddColumnDefinition = (ADD >> !COLUMN >> ColumnDefinition)
;;;


AlterColumnDefinition = (ALTER >> !COLUMN >> ColumnName >> AlterColumnAction)
;;;


AlterColumnAction = SetColumnDefaultClause
  | DropColumnDefaultClause
  | AddColumnScopeClause
  | DropColumnScopeClause
  | AlterIdentityColumnSpecification
;;;


SetColumnDefaultClause = SET >> DefaultClause
;;;


DropColumnDefaultClause = DROP >> DEFAULT
;;;


AddColumnScopeClause = ADD >> ScopeClause
;;;


DropColumnScopeClause = DROP >> SCOPE >> DropBehavior
;;;


AlterIdentityColumnSpecification = +AlterIdentityColumnOption
;;;


AlterIdentityColumnOption = AlterSequenceGeneratorRestartOption
  | SET >> BasicSequenceGeneratorOption
;;;


DropColumnDefinition = (DROP >> !COLUMN >> ColumnName >> DropBehavior)
;;;


AddTableConstraintDefinition = ADD >> TableConstraintDefinition
;;;


DropTableConstraintDefinition = DROP >> CONSTRAINT >> ConstraintName >> DropBehavior
;;;


DropTableStatement = DROP >> TABLE >> TableName >> DropBehavior
;;;


ViewDefinition = (CREATE >> !RECURSIVE >> VIEW >> TableName >> ViewSpecification >> AS >> QueryExpression >> !(WITH >> !LevelsClause >> CHECK >> OPTION))
;;;


ViewSpecification = RegularViewSpecification
  | ReferenceableViewSpecification
;;;


RegularViewSpecification = !(LeftParen >> ViewColumnList >> RightParen)
;;;


ReferenceableViewSpecification = (OF >> PathResolvedUserDefinedTypeName >> !SubviewClause >> !ViewElementList)
;;;


SubviewClause = UNDER >> TableName
;;;


ViewElementList = (LeftParen >> (ViewElement%Comma) >> RightParen)
;;;


ViewElement = SelfReferencingColumnSpecification
  | ViewColumnOption
;;;


ViewColumnOption = ColumnName >> WITH >> OPTIONS >> ScopeClause
;;;


LevelsClause = CASCADED
  | LOCAL
;;;


ViewColumnList = ColumnNameList
;;;


DropViewStatement = DROP >> VIEW >> TableName >> DropBehavior
;;;


DomainDefinition = (CREATE >> DOMAIN >> DomainName >> !AS >> DataType >> !DefaultClause >> *DomainConstraint >> !CollateClause)
;;;


DomainConstraint = !(ConstraintNameDefinition >> CheckConstraintDefinition >> !ConstraintCharacteristics)
;;;


AlterDomainStatement = ALTER >> DOMAIN >> DomainName >> AlterDomainAction
;;;


AlterDomainAction = SetDomainDefaultClause
  | DropDomainDefaultClause
  | AddDomainConstraintDefinition
  | DropDomainConstraintDefinition
;;;


SetDomainDefaultClause = SET >> DefaultClause
;;;


DropDomainDefaultClause = DROP >> DEFAULT
;;;


AddDomainConstraintDefinition = ADD >> DomainConstraint
;;;


DropDomainConstraintDefinition = DROP >> CONSTRAINT >> ConstraintName
;;;


DropDomainStatement = DROP >> DOMAIN >> DomainName >> DropBehavior
;;;


CharacterSetDefinition = (CREATE >> CHARACTER >> SET >> CharacterSetName >> !AS >> CharacterSetSource >> !CollateClause)
;;;


CharacterSetSource = GET >> CharacterSetSpecification
;;;


DropCharacterSetStatement = DROP >> CHARACTER >> SET >> CharacterSetName
;;;


CollationDefinition = (CREATE >> COLLATION >> CollationName >> FOR >> CharacterSetSpecification >> FROM >> ExistingCollationName >> !PadCharacteristic)
;;;


ExistingCollationName = CollationName
;;;


PadCharacteristic = NO >> PAD
  | PAD >> SPACE
;;;


DropCollationStatement = DROP >> COLLATION >> CollationName >> DropBehavior
;;;


TransliterationDefinition = CREATE >> TRANSLATION >> TransliterationName >> FOR >> SourceCharacterSetSpecification >> TO >> TargetCharacterSetSpecification >> FROM >> TransliterationSource
;;;


SourceCharacterSetSpecification = CharacterSetSpecification
;;;


TargetCharacterSetSpecification = CharacterSetSpecification
;;;


TransliterationSource = ExistingTransliterationName
  | TransliterationRoutine
;;;


ExistingTransliterationName = TransliterationName
;;;


TransliterationRoutine = SpecificRoutineDesignator
;;;


DropTransliterationStatement = DROP >> TRANSLATION >> TransliterationName
;;;


AssertionDefinition = (CREATE >> ASSERTION >> ConstraintName >> CHECK >> LeftParen >> SearchCondition >> RightParen >> !ConstraintCharacteristics)
;;;


DropAssertionStatement = DROP >> ASSERTION >> ConstraintName
;;;


TriggerDefinition = (CREATE >> TRIGGER >> TriggerName >> TriggerActionTime >> TriggerEvent >> ON >> TableName >> !REFERENCING >> OldOrNewValuesAliasList >> TriggeredAction)
;;;


TriggerActionTime = BEFORE
  | AFTER
;;;


TriggerEvent = INSERT
  | DELETE
  | (UPDATE >> !OF >> TriggerColumnList)
;;;


TriggerColumnList = ColumnNameList
;;;


TriggeredAction = !((FOR >> EACH >> ROW
  | STATEMENT) >> !WHEN >> LeftParen >> SearchCondition >> RightParen >> TriggeredSQLStatement)
;;;


TriggeredSQLStatement = SQLProcedureStatement
  | (BEGIN >> ATOMIC >> +SQLProcedureStatement >> Semicolon >> END)
;;;


OldOrNewValuesAliasList = +OldOrNewValuesAlias
;;;


OldOrNewValuesAlias = (OLD >> !ROW >> !AS >> OldValuesCorrelationName)
  | (NEW >> !ROW >> !AS >> NewValuesCorrelationName)
  | (OLD >> TABLE >> !AS >> OldValuesTableAlias)
  | (NEW >> TABLE >> !AS >> NewValuesTableAlias)
;;;


OldValuesTableAlias = Identifier
;;;


NewValuesTableAlias = Identifier
;;;


OldValuesCorrelationName = CorrelationName
;;;


NewValuesCorrelationName = CorrelationName
;;;


DropTriggerStatement = DROP >> TRIGGER >> TriggerName
;;;


UserDefinedTypeDefinition = CREATE >> TYPE >> UserDefinedTypeBody
;;;


UserDefinedTypeBody = (SchemaResolvedUserDefinedTypeName >> !SubtypeClause >> !AS >> Representation >> !UserDefinedTypeOptionList >> !MethodSpecificationList)
;;;


UserDefinedTypeOptionList = (UserDefinedTypeOption >> *UserDefinedTypeOption)
;;;


UserDefinedTypeOption = InstantiableClause
  | Finality
  | ReferenceTypeSpecification
  | RefCastOption
  | CastOption
;;;


SubtypeClause = UNDER >> SupertypeName
;;;


SupertypeName = PathResolvedUserDefinedTypeName
;;;


Representation = PredefinedType
  | MemberList
;;;


MemberList = (LeftParen >> (Member%Comma) >> RightParen)
;;;


Member = AttributeDefinition
;;;


InstantiableClause = INSTANTIABLE
  | NOT >> INSTANTIABLE
;;;


Finality = FINAL
  | NOT >> FINAL
;;;


ReferenceTypeSpecification = UserDefinedRepresentation
  | DerivedRepresentation
  | SystemGeneratedRepresentation
;;;


UserDefinedRepresentation = REF >> USING >> PredefinedType
;;;


DerivedRepresentation = REF >> FROM >> ListOfAttributes
;;;


SystemGeneratedRepresentation = REF >> IS >> SYSTEM >> GENERATED
;;;


RefCastOption = !(CastToRef >> !CastToType)
;;;


CastToRef = CAST >> LeftParen >> SOURCE >> AS >> REF >> RightParen >> WITH >> CastToRefIdentifier
;;;


CastToRefIdentifier = Identifier
;;;


CastToType = CAST >> LeftParen >> REF >> AS >> SOURCE >> RightParen >> WITH >> CastToTypeIdentifier
;;;


CastToTypeIdentifier = Identifier
;;;


ListOfAttributes = (LeftParen >> (AttributeName%Comma) >> RightParen)
;;;


CastOption = !(CastToDistinct >> !CastToSource)
;;;


CastToDistinct = CAST >> LeftParen >> SOURCE >> AS >> DISTINCT >> RightParen >> WITH >> CastToDistinctIdentifier
;;;


CastToDistinctIdentifier = Identifier
;;;


CastToSource = CAST >> LeftParen >> DISTINCT >> AS >> SOURCE >> RightParen >> WITH >> CastToSourceIdentifier
;;;


CastToSourceIdentifier = Identifier
;;;


MethodSpecificationList = ((MethodSpecification%Comma))
;;;


MethodSpecification = OriginalMethodSpecification
  | OverridingMethodSpecification
;;;


OriginalMethodSpecification = (PartialMethodSpecification >> !SELF >> AS >> RESULT >> !SELF >> AS >> LOCATOR >> !MethodCharacteristics)
;;;


OverridingMethodSpecification = OVERRIDING >> PartialMethodSpecification
;;;


PartialMethodSpecification = !(INSTANCE
  | STATIC
  | CONSTRUCTOR >> METHOD >> MethodName >> SQLParameterDeclarationList >> ReturnsClause >> !SPECIFIC >> SpecificMethodName)
;;;


SpecificMethodName = !(SchemaName >> Period >> QualifiedIdentifier)
;;;


MethodCharacteristics = +MethodCharacteristic
;;;


MethodCharacteristic = LanguageClause
  | ParameterStyleClause
  | DeterministicCharacteristic
  | SQLDataAccessIndication
  | NullCallClause
;;;


AttributeDefinition = (AttributeName >> DataType >> !ReferenceScopeCheck >> !AttributeDefault >> !CollateClause)
;;;


AttributeDefault = DefaultClause
;;;


AlterTypeStatement = ALTER >> TYPE >> SchemaResolvedUserDefinedTypeName >> AlterTypeAction
;;;


AlterTypeAction = AddAttributeDefinition
  | DropAttributeDefinition
  | AddOriginalMethodSpecification
  | AddOverridingMethodSpecification
  | DropMethodSpecification
;;;


AddAttributeDefinition = ADD >> ATTRIBUTE >> AttributeDefinition
;;;


DropAttributeDefinition = DROP >> ATTRIBUTE >> AttributeName >> RESTRICT
;;;


AddOriginalMethodSpecification = ADD >> OriginalMethodSpecification
;;;


AddOverridingMethodSpecification = ADD >> OverridingMethodSpecification
;;;


DropMethodSpecification = DROP >> SpecificMethodSpecificationDesignator >> RESTRICT
;;;


SpecificMethodSpecificationDesignator = !(INSTANCE
  | STATIC
  | CONSTRUCTOR >> METHOD >> MethodName >> DataTypeList)
;;;


DropDataTypeStatement = DROP >> TYPE >> SchemaResolvedUserDefinedTypeName >> DropBehavior
;;;


SQLInvokedRoutine = SchemaRoutine
;;;


SchemaRoutine = SchemaProcedure
  | SchemaFunction
;;;


SchemaProcedure = CREATE >> SQLInvokedProcedure
;;;


SchemaFunction = CREATE >> SQLInvokedFunction
;;;


SQLInvokedProcedure = PROCEDURE >> SchemaQualifiedRoutineName >> SQLParameterDeclarationList >> RoutineCharacteristics >> RoutineBody
;;;


SQLInvokedFunction = (FunctionSpecification
  | MethodSpecificationDesignator >> RoutineBody)
;;;


SQLParameterDeclarationList = (LeftParen >> !((SQLParameterDeclaration%Comma)) >> RightParen)
;;;


SQLParameterDeclaration = !(ParameterMode >> !SQLParameterName >> ParameterType >> !RESULT)
;;;


ParameterMode = IN
  | OUT
  | INOUT
;;;


ParameterType = (DataType >> !LocatorIndication)
;;;


LocatorIndication = AS >> LOCATOR
;;;


FunctionSpecification = (FUNCTION >> SchemaQualifiedRoutineName >> SQLParameterDeclarationList >> ReturnsClause >> RoutineCharacteristics >> !DispatchClause)
;;;


MethodSpecificationDesignator = SPECIFIC >> METHOD >> SpecificMethodName
  | !(INSTANCE
  | STATIC
  | CONSTRUCTOR >> METHOD >> MethodName >> SQLParameterDeclarationList >> !ReturnsClause >> FOR >> SchemaResolvedUserDefinedTypeName)
;;;


RoutineCharacteristics = *(RoutineCharacteristic)
;;;


RoutineCharacteristic = LanguageClause
  | ParameterStyleClause
  | SPECIFIC >> SpecificName
  | DeterministicCharacteristic
  | SQLDataAccessIndication
  | NullCallClause
  | DynamicResultSetsCharacteristic
  | SavepointLevelIndication
;;;


SavepointLevelIndication = NEW >> SAVEPOINT >> LEVEL
  | OLD >> SAVEPOINT >> LEVEL
;;;


DynamicResultSetsCharacteristic = DYNAMIC >> RESULT >> SETS >> MaximumDynamicResultSets
;;;


ParameterStyleClause = PARAMETER >> STYLE >> ParameterStyle
;;;


DispatchClause = STATIC >> DISPATCH
;;;


ReturnsClause = RETURNS >> ReturnsType
;;;


ReturnsType = (ReturnsDataType >> !ResultCast)
  | ReturnsTableType
;;;


ReturnsTableType = TABLE >> TableFunctionColumnList
;;;


TableFunctionColumnList = (LeftParen >> (TableFunctionColumnListElement%Comma) >> RightParen)
;;;


TableFunctionColumnListElement = ColumnName >> DataType
;;;


ResultCast = CAST >> FROM >> ResultCastFromType
;;;


ResultCastFromType = (DataType >> !LocatorIndication)
;;;


ReturnsDataType = (DataType >> !LocatorIndication)
;;;


RoutineBody = SQLRoutineSpec
  | ExternalBodyReference
;;;


SQLRoutineSpec = !(RightsClause >> SQLRoutineBody)
;;;


RightsClause = SQL >> SECURITY >> INVOKER
  | SQL >> SECURITY >> DEFINER
;;;


SQLRoutineBody = SQLProcedureStatement
;;;


ExternalBodyReference = (EXTERNAL >> !NAME >> ExternalRoutineName >> !ParameterStyleClause >> !TransformGroupSpecification >> !ExternalSecurityClause)
;;;


ExternalSecurityClause = EXTERNAL >> SECURITY >> DEFINER
  | EXTERNAL >> SECURITY >> INVOKER
  | EXTERNAL >> SECURITY >> IMPLEMENTATION >> DEFINED
;;;


ParameterStyle = SQL
  | GENERAL
;;;


DeterministicCharacteristic = DETERMINISTIC
  | NOT >> DETERMINISTIC
;;;


SQLDataAccessIndication = NO >> SQL
  | CONTAINS >> SQL
  | READS >> SQL >> DATA
  | MODIFIES >> SQL >> DATA
;;;


NullCallClause = RETURNS >> NULL >> ON >> NULL >> INPUT
  | CALLED >> ON >> NULL >> INPUT
;;;


MaximumDynamicResultSets = UnsignedInteger
;;;


TransformGroupSpecification = (TRANSFORM >> GROUP >> SingleGroupSpecification
  | MultipleGroupSpecification)
;;;


SingleGroupSpecification = GroupName
;;;


MultipleGroupSpecification = ((GroupSpecification%Comma))
;;;


GroupSpecification = GroupName >> FOR >> TYPE >> PathResolvedUserDefinedTypeName
;;;


AlterRoutineStatement = ALTER >> SpecificRoutineDesignator >> AlterRoutineCharacteristics >> AlterRoutineBehavior
;;;


AlterRoutineCharacteristics = +AlterRoutineCharacteristic
;;;


AlterRoutineCharacteristic = LanguageClause
  | ParameterStyleClause
  | SQLDataAccessIndication
  | NullCallClause
  | DynamicResultSetsCharacteristic
  | NAME >> ExternalRoutineName
;;;


AlterRoutineBehavior = RESTRICT
;;;


DropRoutineStatement = DROP >> SpecificRoutineDesignator >> DropBehavior
;;;


UserDefinedCastDefinition = (CREATE >> CAST >> LeftParen >> SourceDataType >> AS >> TargetDataType >> RightParen >> WITH >> CastFunction >> !AS >> ASSIGNMENT)
;;;


CastFunction = SpecificRoutineDesignator
;;;


SourceDataType = DataType
;;;


TargetDataType = DataType
;;;


DropUserDefinedCastStatement = DROP >> CAST >> LeftParen >> SourceDataType >> AS >> TargetDataType >> RightParen >> DropBehavior
;;;


UserDefinedOrderingDefinition = CREATE >> ORDERING >> FOR >> SchemaResolvedUserDefinedTypeName >> OrderingForm
;;;


OrderingForm = EqualsOrderingForm
  | FullOrderingForm
;;;


EqualsOrderingForm = EQUALS >> ONLY >> BY >> OrderingCategory
;;;


FullOrderingForm = ORDER >> FULL >> BY >> OrderingCategory
;;;


OrderingCategory = RelativeCategory
  | MapCategory
  | StateCategory
;;;


RelativeCategory = RELATIVE >> WITH >> RelativeFunctionSpecification
;;;


MapCategory = MAP >> WITH >> MapFunctionSpecification
;;;


StateCategory = (STATE >> !SpecificName)
;;;


RelativeFunctionSpecification = SpecificRoutineDesignator
;;;


MapFunctionSpecification = SpecificRoutineDesignator
;;;


DropUserDefinedOrderingStatement = DROP >> ORDERING >> FOR >> SchemaResolvedUserDefinedTypeName >> DropBehavior
;;;


TransformDefinition = (CREATE >> TRANSFORM
  | TRANSFORMS >> FOR >> SchemaResolvedUserDefinedTypeName >> +TransformGroup)
;;;


TransformGroup = GroupName >> LeftParen >> TransformElementList >> RightParen
;;;


GroupName = Identifier
;;;


TransformElementList = (TransformElement >> !Comma >> TransformElement)
;;;


TransformElement = ToSql
  | FromSql
;;;


ToSql = TO >> SQL >> WITH >> ToSqlFunction
;;;


FromSql = FROM >> SQL >> WITH >> FromSqlFunction
;;;


ToSqlFunction = SpecificRoutineDesignator
;;;


FromSqlFunction = SpecificRoutineDesignator
;;;


AlterTransformStatement = (ALTER >> TRANSFORM
  | TRANSFORMS >> FOR >> SchemaResolvedUserDefinedTypeName >> +AlterGroup)
;;;


AlterGroup = GroupName >> LeftParen >> AlterTransformActionList >> RightParen
;;;


AlterTransformActionList = ((AlterTransformAction%Comma))
;;;


AlterTransformAction = AddTransformElementList
  | DropTransformElementList
;;;


AddTransformElementList = ADD >> LeftParen >> TransformElementList >> RightParen
;;;


DropTransformElementList = (DROP >> LeftParen >> TransformKind >> !Comma >> TransformKind >> DropBehavior >> RightParen)
;;;


TransformKind = TO >> SQL
  | FROM >> SQL
;;;


DropTransformStatement = (DROP >> TRANSFORM
  | TRANSFORMS >> TransformsToBeDropped >> FOR >> SchemaResolvedUserDefinedTypeName >> DropBehavior)
;;;


TransformsToBeDropped = ALL
  | TransformGroupElement
;;;


TransformGroupElement = GroupName
;;;


SequenceGeneratorDefinition = (CREATE >> SEQUENCE >> SequenceGeneratorName >> !SequenceGeneratorOptions)
;;;


SequenceGeneratorOptions = +SequenceGeneratorOption
;;;


SequenceGeneratorOption = SequenceGeneratorDataTypeOption
  | CommonSequenceGeneratorOptions
;;;


CommonSequenceGeneratorOptions = +CommonSequenceGeneratorOption
;;;


CommonSequenceGeneratorOption = SequenceGeneratorStartWithOption
  | BasicSequenceGeneratorOption
;;;


BasicSequenceGeneratorOption = SequenceGeneratorIncrementByOption
  | SequenceGeneratorMaxvalueOption
  | SequenceGeneratorMinvalueOption
  | SequenceGeneratorCycleOption
;;;


SequenceGeneratorDataTypeOption = AS >> DataType
;;;


SequenceGeneratorStartWithOption = START >> WITH >> SequenceGeneratorStartValue
;;;


SequenceGeneratorStartValue = SignedNumericLiteral
;;;


SequenceGeneratorIncrementByOption = INCREMENT >> BY >> SequenceGeneratorIncrement
;;;


SequenceGeneratorIncrement = SignedNumericLiteral
;;;


SequenceGeneratorMaxvalueOption = MAXVALUE >> SequenceGeneratorMaxValue
  | NO >> MAXVALUE
;;;


SequenceGeneratorMaxValue = SignedNumericLiteral
;;;


SequenceGeneratorMinvalueOption = MINVALUE >> SequenceGeneratorMinValue
  | NO >> MINVALUE
;;;


SequenceGeneratorMinValue = SignedNumericLiteral
;;;


SequenceGeneratorCycleOption = CYCLE
  | NO >> CYCLE
;;;


AlterSequenceGeneratorStatement = ALTER >> SEQUENCE >> SequenceGeneratorName >> AlterSequenceGeneratorOptions
;;;


AlterSequenceGeneratorOptions = +AlterSequenceGeneratorOption
;;;


AlterSequenceGeneratorOption = AlterSequenceGeneratorRestartOption
  | BasicSequenceGeneratorOption
;;;


AlterSequenceGeneratorRestartOption = RESTART >> WITH >> SequenceGeneratorRestartValue
;;;


SequenceGeneratorRestartValue = SignedNumericLiteral
;;;


DropSequenceGeneratorStatement = DROP >> SEQUENCE >> SequenceGeneratorName >> DropBehavior
;;;


GrantStatement = GrantPrivilegeStatement
  | GrantRoleStatement
;;;


GrantPrivilegeStatement = (GRANT >> Privileges >> TO >> (Grantee%Comma) >> !WITH >> HIERARCHY >> OPTION >> !WITH >> GRANT >> OPTION >> !GRANTED >> BY >> Grantor)
;;;


Privileges = ObjectPrivileges >> ON >> ObjectName
;;;


ObjectName = !(TABLE >> TableName)
  | DOMAIN >> DomainName
  | COLLATION >> CollationName
  | CHARACTER >> SET >> CharacterSetName
  | TRANSLATION >> TransliterationName
  | TYPE >> SchemaResolvedUserDefinedTypeName
  | SEQUENCE >> SequenceGeneratorName
  | SpecificRoutineDesignator
;;;


ObjectPrivileges = ALL >> PRIVILEGES
  | ((Action%Comma))
;;;


Action = SELECT
  | SELECT >> LeftParen >> PrivilegeColumnList >> RightParen
  | SELECT >> LeftParen >> PrivilegeMethodList >> RightParen
  | DELETE
  | (INSERT >> !LeftParen >> PrivilegeColumnList >> RightParen)
  | (UPDATE >> !LeftParen >> PrivilegeColumnList >> RightParen)
  | (REFERENCES >> !LeftParen >> PrivilegeColumnList >> RightParen)
  | USAGE
  | TRIGGER
  | UNDER
  | EXECUTE
;;;


PrivilegeMethodList = ((SpecificRoutineDesignator%Comma))
;;;


PrivilegeColumnList = ColumnNameList
;;;


Grantee = PUBLIC
  | AuthorizationIdentifier
;;;


Grantor = CURRENT_USER
  | CURRENT_ROLE
;;;


RoleDefinition = (CREATE >> ROLE >> RoleName >> !WITH >> ADMIN >> Grantor)
;;;


GrantRoleStatement = (GRANT >> (RoleGranted%Comma) >> TO >> (Grantee%Comma) >> !WITH >> ADMIN >> OPTION >> !GRANTED >> BY >> Grantor)
;;;


RoleGranted = RoleName
;;;


DropRoleStatement = DROP >> ROLE >> RoleName
;;;


RevokeStatement = RevokePrivilegeStatement
  | RevokeRoleStatement
;;;


RevokePrivilegeStatement = (REVOKE >> !RevokeOptionExtension >> Privileges >> FROM >> (Grantee%Comma) >> !GRANTED >> BY >> Grantor >> DropBehavior)
;;;


RevokeOptionExtension = GRANT >> OPTION >> FOR
  | HIERARCHY >> OPTION >> FOR
;;;


RevokeRoleStatement = (REVOKE >> !ADMIN >> OPTION >> FOR >> (RoleRevoked%Comma) >> FROM >> (Grantee%Comma) >> !GRANTED >> BY >> Grantor >> DropBehavior)
;;;


RoleRevoked = RoleName
;;;


SQLClientModuleDefinition = (ModuleNameClause >> LanguageClause >> ModuleAuthorizationClause >> !ModulePathSpecification >> !ModuleTransformGroupSpecification >> !ModuleCollation >> *TemporaryTableDeclaration >> +ModuleContents)
;;;


ModuleAuthorizationClause = SCHEMA >> SchemaName
  | (AUTHORIZATION >> ModuleAuthorizationIdentifier >> !(FOR >> STATIC >> ONLY
  | AND >> DYNAMIC))
  | (SCHEMA >> SchemaName >> AUTHORIZATION >> ModuleAuthorizationIdentifier >> !(FOR >> STATIC >> ONLY
  | AND >> DYNAMIC))
;;;


ModuleAuthorizationIdentifier = AuthorizationIdentifier
;;;


ModulePathSpecification = PathSpecification
;;;


ModuleTransformGroupSpecification = TransformGroupSpecification
;;;


ModuleCollations = +ModuleCollationSpecification
;;;


ModuleCollationSpecification = (COLLATION >> CollationName >> !FOR >> CharacterSetSpecificationList)
;;;


CharacterSetSpecificationList = ((CharacterSetSpecification%Comma))
;;;


ModuleContents = DeclareCursor
  | DynamicDeclareCursor
  | ExternallyInvokedProcedure
;;;


ModuleNameClause = (MODULE >> !SQLClientModuleName >> !ModuleCharacterSetSpecification)
;;;


ModuleCharacterSetSpecification = NAMES >> ARE >> CharacterSetSpecification
;;;


ExternallyInvokedProcedure = PROCEDURE >> ProcedureName >> HostParameterDeclarationList >> Semicolon >> SQLProcedureStatement >> Semicolon
;;;


HostParameterDeclarationList = (LeftParen >> (HostParameterDeclaration%Comma) >> RightParen)
;;;


HostParameterDeclaration = HostParameterName >> HostParameterDataType
  | StatusParameter
;;;


HostParameterDataType = (DataType >> !LocatorIndication)
;;;


StatusParameter = SQLSTATE
;;;


SQLProcedureStatement = SQLExecutableStatement
;;;


SQLExecutableStatement = SQLSchemaStatement
  | SQLDataStatement
  | SQLControlStatement
  | SQLTransactionStatement
  | SQLConnectionStatement
  | SQLSessionStatement
  | SQLDiagnosticsStatement
  | SQLDynamicStatement
;;;


SQLSchemaStatement = SQLSchemaDefinitionStatement
  | SQLSchemaManipulationStatement
;;;


SQLSchemaDefinitionStatement = SchemaDefinition
  | TableDefinition
  | ViewDefinition
  | SQLInvokedRoutine
  | GrantStatement
  | RoleDefinition
  | DomainDefinition
  | CharacterSetDefinition
  | CollationDefinition
  | TransliterationDefinition
  | AssertionDefinition
  | TriggerDefinition
  | UserDefinedTypeDefinition
  | UserDefinedCastDefinition
  | UserDefinedOrderingDefinition
  | TransformDefinition
  | SequenceGeneratorDefinition
;;;


SQLSchemaManipulationStatement = DropSchemaStatement
  | AlterTableStatement
  | DropTableStatement
  | DropViewStatement
  | AlterRoutineStatement
  | DropRoutineStatement
  | DropUserDefinedCastStatement
  | RevokeStatement
  | DropRoleStatement
  | AlterDomainStatement
  | DropDomainStatement
  | DropCharacterSetStatement
  | DropCollationStatement
  | DropTransliterationStatement
  | DropAssertionStatement
  | DropTriggerStatement
  | AlterTypeStatement
  | DropDataTypeStatement
  | DropUserDefinedOrderingStatement
  | AlterTransformStatement
  | DropTransformStatement
  | AlterSequenceGeneratorStatement
  | DropSequenceGeneratorStatement
;;;


SQLDataStatement = OpenStatement
  | FetchStatement
  | CloseStatement
  | SelectStatementSingleRow
  | FreeLocatorStatement
  | HoldLocatorStatement
  | SQLDataChangeStatement
;;;


SQLDataChangeStatement = DeleteStatementPositioned
  | DeleteStatementSearched
  | InsertStatement
  | UpdateStatementPositioned
  | UpdateStatementSearched
  | MergeStatement
;;;


SQLControlStatement = CallStatement
  | ReturnStatement
;;;


SQLTransactionStatement = StartTransactionStatement
  | SetTransactionStatement
  | SetConstraintsModeStatement
  | SavepointStatement
  | ReleaseSavepointStatement
  | CommitStatement
  | RollbackStatement
;;;


SQLConnectionStatement = ConnectStatement
  | SetConnectionStatement
  | DisconnectStatement
;;;


SQLSessionStatement = SetSessionUserIdentifierStatement
  | SetRoleStatement
  | SetLocalTimeZoneStatement
  | SetSessionCharacteristicsStatement
  | SetCatalogStatement
  | SetSchemaStatement
  | SetNamesStatement
  | SetPathStatement
  | SetTransformGroupStatement
  | SetSessionCollationStatement
;;;


SQLDiagnosticsStatement = GetDiagnosticsStatement
;;;


SQLDynamicStatement = SystemDescriptorStatement
  | PrepareStatement
  | DeallocatePreparedStatement
  | DescribeStatement
  | ExecuteStatement
  | ExecuteImmediateStatement
  | SQLDynamicDataStatement
;;;


SQLDynamicDataStatement = AllocateCursorStatement
  | DynamicOpenStatement
  | DynamicFetchStatement
  | DynamicCloseStatement
  | DynamicDeleteStatementPositioned
  | DynamicUpdateStatementPositioned
;;;


SystemDescriptorStatement = AllocateDescriptorStatement
  | DeallocateDescriptorStatement
  | SetDescriptorStatement
  | GetDescriptorStatement >> Table >> 16--Data >> type >> correspondences >> for >> C
;;;


DeclareCursor = (DECLARE >> CursorName >> !CursorSensitivity >> !CursorScrollability >> CURSOR >> !CursorHoldability >> !CursorReturnability >> FOR >> CursorSpecification)
;;;


CursorSensitivity = SENSITIVE
  | INSENSITIVE
  | ASENSITIVE
;;;


CursorScrollability = SCROLL
  | NO >> SCROLL
;;;


CursorHoldability = WITH >> HOLD
  | WITHOUT >> HOLD
;;;


CursorReturnability = WITH >> RETURN
  | WITHOUT >> RETURN
;;;


CursorSpecification = (QueryExpression >> !OrderByClause >> !UpdatabilityClause)
;;;


UpdatabilityClause = (FOR >> READ >> ONLY
  | (UPDATE >> !OF >> ColumnNameList))
;;;


OrderByClause = ORDER >> BY >> SortSpecificationList
;;;


OpenStatement = OPEN >> CursorName
;;;


FetchStatement = (FETCH >> !!(FetchOrientation >> FROM) >> CursorName >> INTO >> FetchTargetList)
;;;


FetchOrientation = NEXT
  | PRIOR
  | FIRST
  | LAST
  | (ABSOLUTE
  | RELATIVE >> SimpleValueSpecification)
;;;


FetchTargetList = ((TargetSpecification%Comma) >> Close >> a >> cursor).
;;;


CloseStatement = CLOSE >> CursorName
;;;


SelectStatementSingleRow = (SELECT >> !SetQuantifier >> SelectList >> INTO >> SelectTargetList >> TableExpression)
;;;


SelectTargetList = ((TargetSpecification%Comma))
;;;


DeleteStatementPositioned = DELETE >> FROM >> TargetTable >> WHERE >> CURRENT >> OF >> CursorName
;;;


TargetTable = TableName
  | ONLY >> LeftParen >> TableName >> RightParen
;;;


DeleteStatementSearched = (DELETE >> FROM >> TargetTable >> !WHERE >> SearchCondition)
;;;


InsertStatement = INSERT >> INTO >> InsertionTarget >> InsertColumnsAndSource
;;;


InsertionTarget = TableName
;;;


InsertColumnsAndSource = FromSubquery
  | FromConstructor
  | FromDefault
;;;


FromSubquery = !(LeftParen >> InsertColumnList >> RightParen >> !OverrideClause >> QueryExpression)
;;;


FromConstructor = !(LeftParen >> InsertColumnList >> RightParen >> !OverrideClause >> ContextuallyTypedTableValueConstructor)
;;;


OverrideClause = OVERRIDING >> USER >> VALUE
  | OVERRIDING >> SYSTEM >> VALUE
;;;


FromDefault = DEFAULT >> VALUES
;;;


InsertColumnList = ColumnNameList
;;;


MergeStatement = (MERGE >> INTO >> TargetTable >> !!(AS >> MergeCorrelationName) >> USING >> TableReference >> ON >> SearchCondition >> MergeOperationSpecification)
;;;


MergeCorrelationName = CorrelationName
;;;


MergeOperationSpecification = +MergeWhenClause
;;;


MergeWhenClause = MergeWhenMatchedClause
  | MergeWhenNotMatchedClause
;;;


MergeWhenMatchedClause = WHEN >> MATCHED >> THEN >> MergeUpdateSpecification
;;;


MergeWhenNotMatchedClause = WHEN >> NOT >> MATCHED >> THEN >> MergeInsertSpecification
;;;


MergeUpdateSpecification = UPDATE >> SET >> SetClauseList
;;;


MergeInsertSpecification = (INSERT >> !LeftParen >> InsertColumnList >> RightParen >> !OverrideClause >> VALUES >> MergeInsertValueList)
;;;


MergeInsertValueList = (LeftParen >> (MergeInsertValueElement%Comma) >> RightParen)
;;;


MergeInsertValueElement = ValueExpression
  | ContextuallyTypedValueSpecification
;;;


UpdateStatementPositioned = UPDATE >> TargetTable >> SET >> SetClauseList >> WHERE >> CURRENT >> OF >> CursorName
;;;


UpdateStatementSearched = (UPDATE >> TargetTable >> SET >> SetClauseList >> !WHERE >> SearchCondition)
;;;


SetClauseList = ((SetClause%Comma))
;;;


SetClause = MultipleColumnAssignment
  | SetTarget >> EqualsOperator >> UpdateSource
;;;


SetTarget = UpdateTarget
  | MutatedSetClause
;;;


MultipleColumnAssignment = SetTargetList >> EqualsOperator >> AssignedRow
;;;


SetTargetList = (LeftParen >> (SetTarget%Comma) >> RightParen)
;;;


AssignedRow = ContextuallyTypedRowValueExpression
;;;


UpdateTarget = ObjectColumn
  | ObjectColumn >> LeftBracketOrTrigraph >> SimpleValueSpecification >> RightBracketOrTrigraph
;;;


ObjectColumn = ColumnName
;;;


MutatedSetClause = MutatedTarget >> Period >> MethodName
;;;


MutatedTarget = ObjectColumn
  | MutatedSetClause
;;;


UpdateSource = ValueExpression
  | ContextuallyTypedValueSpecification
;;;


TemporaryTableDeclaration = (DECLARE >> LOCAL >> TEMPORARY >> TABLE >> TableName >> TableElementList >> !ON >> COMMIT >> TableCommitAction >> ROWS)
;;;


FreeLocatorStatement = (FREE >> LOCATOR >> (LocatorReference%Comma))
;;;


LocatorReference = HostParameterName
  | EmbeddedVariableName
;;;


HoldLocatorStatement = (HOLD >> LOCATOR >> (LocatorReference%Comma))
;;;


CallStatement = CALL >> RoutineInvocation
;;;


ReturnStatement = RETURN >> ReturnValue
;;;


ReturnValue = ValueExpression
  | NULL
;;;


StartTransactionStatement = (START >> TRANSACTION >> !((TransactionMode%Comma)))
;;;


TransactionMode = IsolationLevel
  | TransactionAccessMode
  | DiagnosticsSize
;;;


TransactionAccessMode = READ >> ONLY
  | READ >> WRITE
;;;


IsolationLevel = ISOLATION >> LEVEL >> LevelOfIsolation
;;;


LevelOfIsolation = READ >> UNCOMMITTED
  | READ >> COMMITTED
  | REPEATABLE >> READ
  | SERIALIZABLE
;;;


DiagnosticsSize = DIAGNOSTICS >> SIZE >> NumberOfConditions
;;;


NumberOfConditions = SimpleValueSpecification
;;;


SetTransactionStatement = (SET >> !LOCAL >> TransactionCharacteristics)
;;;


TransactionCharacteristics = (TRANSACTION >> (TransactionMode%Comma))
;;;


SetConstraintsModeStatement = (SET >> CONSTRAINTS >> ConstraintNameList >> DEFERRED
  | IMMEDIATE)
;;;


ConstraintNameList = ALL
  | ((ConstraintName%Comma))
;;;


SavepointStatement = SAVEPOINT >> SavepointSpecifier
;;;


SavepointSpecifier = SavepointName
;;;


ReleaseSavepointStatement = RELEASE >> SAVEPOINT >> SavepointSpecifier
;;;


CommitStatement = (COMMIT >> !WORK >> !(AND >> !NO >> CHAIN))
;;;


RollbackStatement = (ROLLBACK >> !WORK >> !(AND >> !NO >> CHAIN) >> !SavepointClause)
;;;


SavepointClause = TO >> SAVEPOINT >> SavepointSpecifier
;;;


ConnectStatement = CONNECT >> TO >> ConnectionTarget
;;;


ConnectionTarget = (SQLServerName >> !AS >> ConnectionName >> !USER >> ConnectionUserName)
  | DEFAULT
;;;


SetConnectionStatement = SET >> CONNECTION >> ConnectionObject
;;;


ConnectionObject = DEFAULT
  | ConnectionName
;;;


DisconnectStatement = DISCONNECT >> DisconnectObject
;;;


DisconnectObject = ConnectionObject
  | ALL
  | CURRENT
;;;


SetSessionCharacteristicsStatement = SET >> SESSION >> CHARACTERISTICS >> AS >> SessionCharacteristicList
;;;


SessionCharacteristicList = ((SessionCharacteristic%Comma))
;;;


SessionCharacteristic = TransactionCharacteristics
;;;


SetSessionUserIdentifierStatement = SET >> SESSION >> AUTHORIZATION >> ValueSpecification
;;;


SetRoleStatement = SET >> ROLE >> RoleSpecification
;;;


RoleSpecification = ValueSpecification
  | NONE
;;;


SetLocalTimeZoneStatement = SET >> TIME >> ZONE >> SetTimeZoneValue
;;;


SetTimeZoneValue = IntervalValueExpression
  | LOCAL
;;;


SetCatalogStatement = SET >> CatalogNameCharacteristic
;;;


CatalogNameCharacteristic = CATALOG >> ValueSpecification
;;;


SetSchemaStatement = SET >> SchemaNameCharacteristic
;;;


SchemaNameCharacteristic = SCHEMA >> ValueSpecification
;;;


SetNamesStatement = SET >> CharacterSetNameCharacteristic
;;;


CharacterSetNameCharacteristic = NAMES >> ValueSpecification
;;;


SetPathStatement = SET >> SQLPathCharacteristic
;;;


SQLPathCharacteristic = PATH >> ValueSpecification
;;;


SetTransformGroupStatement = SET >> TransformGroupCharacteristic
;;;


TransformGroupCharacteristic = DEFAULT >> TRANSFORM >> GROUP >> ValueSpecification
  | TRANSFORM >> GROUP >> FOR >> TYPE >> PathResolvedUserDefinedTypeName >> ValueSpecification
;;;


SetSessionCollationStatement = (SET >> COLLATION >> CollationSpecification >> !FOR >> CharacterSetSpecificationList)
  | (SET >> NO >> COLLATION >> !FOR >> CharacterSetSpecificationList)
;;;


CharacterSetSpecificationList = (CharacterSetSpecification >> !,+CharacterSetSpecification)
;;;


CollationSpecification = ValueSpecification
;;;


AllocateDescriptorStatement = (ALLOCATE >> !SQL >> DESCRIPTOR >> DescriptorName >> !WITH >> MAX >> Occurrences)
;;;


Occurrences = SimpleValueSpecification
;;;


DeallocateDescriptorStatement = (DEALLOCATE >> !SQL >> DESCRIPTOR >> DescriptorName)
;;;


GetDescriptorStatement = (GET >> !SQL >> DESCRIPTOR >> DescriptorName >> GetDescriptorInformation)
;;;


GetDescriptorInformation = ((GetHeaderInformation%Comma))
  | (VALUE >> ItemNumber >> (GetItemInformation%Comma))
;;;


GetHeaderInformation = SimpleTargetSpecification1 >> EqualsOperator >> HeaderItemName
;;;


HeaderItemName = COUNT
  | KEY_TYPE
  | DYNAMIC_FUNCTION
  | DYNAMIC_FUNCTION_CODE
  | TOP_LEVEL_COUNT
;;;


GetItemInformation = SimpleTargetSpecification2 >> EqualsOperator >> DescriptorItemName
;;;


ItemNumber = SimpleValueSpecification
;;;


SimpleTargetSpecification1 = SimpleTargetSpecification
;;;


SimpleTargetSpecification2 = SimpleTargetSpecification
;;;


DescriptorItemName = CARDINALITY
  | CHARACTER_SET_CATALOG
  | CHARACTER_SET_NAME
  | CHARACTER_SET_SCHEMA
  | COLLATION_CATALOG
  | COLLATION_NAME
  | COLLATION_SCHEMA
  | DATA
  | DATETIME_INTERVAL_CODE
  | DATETIME_INTERVAL_PRECISION
  | DEGREE
  | INDICATOR
  | KEY_MEMBER
  | LENGTH
  | LEVEL
  | NAME
  | NULLABLE
  | OCTET_LENGTH
  | PARAMETER_MODE
  | PARAMETER_ORDINAL_POSITION
  | PARAMETER_SPECIFIC_CATALOG
  | PARAMETER_SPECIFIC_NAME
  | PARAMETER_SPECIFIC_SCHEMA
  | PRECISION
  | RETURNED_CARDINALITY
  | RETURNED_LENGTH
  | RETURNED_OCTET_LENGTH
  | SCALE
  | SCOPE_CATALOG
  | SCOPE_NAME
  | SCOPE_SCHEMA
  | TYPE
  | UNNAMED
  | USER_DEFINED_TYPE_CATALOG
  | USER_DEFINED_TYPE_NAME
  | USER_DEFINED_TYPE_SCHEMA
  | USER_DEFINED_TYPE_CODE
;;;


SetDescriptorStatement = (SET >> !SQL >> DESCRIPTOR >> DescriptorName >> SetDescriptorInformation)
;;;


SetDescriptorInformation = ((SetHeaderInformation%Comma))
  | (VALUE >> ItemNumber >> (SetItemInformation%Comma))
;;;


SetHeaderInformation = HeaderItemName >> EqualsOperator >> SimpleValueSpecification1
;;;


SetItemInformation = DescriptorItemName >> EqualsOperator >> SimpleValueSpecification2
;;;


SimpleValueSpecification1 = SimpleValueSpecification
;;;


SimpleValueSpecification2 = SimpleValueSpecification
;;;


ItemNumber = SimpleValueSpecification
;;;


PrepareStatement = (PREPARE >> SQLStatementName >> !AttributesSpecification >> FROM >> SQLStatementVariable)
;;;


AttributesSpecification = ATTRIBUTES >> AttributesVariable
;;;


AttributesVariable = SimpleValueSpecification
;;;


SQLStatementVariable = SimpleValueSpecification
;;;


PreparableStatement = PreparableSQLDataStatement
  | PreparableSQLSchemaStatement
  | PreparableSQLTransactionStatement
  | PreparableSQLControlStatement
  | PreparableSQLSessionStatement
  | PreparableImplementationDefinedStatement
;;;


PreparableSQLDataStatement = DeleteStatementSearched
  | DynamicSingleRowSelectStatement
  | InsertStatement
  | DynamicSelectStatement
  | UpdateStatementSearched
  | MergeStatement
  | PreparableDynamicDeleteStatementPositioned
  | PreparableDynamicUpdateStatementPositioned
;;;


PreparableSQLSchemaStatement = SQLSchemaStatement
;;;


PreparableSQLTransactionStatement = SQLTransactionStatement
;;;


PreparableSQLControlStatement = SQLControlStatement
;;;


PreparableSQLSessionStatement = SQLSessionStatement
;;;


DynamicSelectStatement = CursorSpecification
;;;


PreparableImplementationDefinedStatement = !!See >> the >> Syntax >> Rules.
;;;


CursorAttributes = +CursorAttribute
;;;


CursorAttribute = CursorSensitivity
  | CursorScrollability
  | CursorHoldability
  | CursorReturnability
;;;


DeallocatePreparedStatement = DEALLOCATE >> PREPARE >> SQLStatementName
;;;


DescribeStatement = DescribeInputStatement
  | DescribeOutputStatement
;;;


DescribeInputStatement = (DESCRIBE >> INPUT >> SQLStatementName >> UsingDescriptor >> !NestingOption)
;;;


DescribeOutputStatement = (DESCRIBE >> !OUTPUT >> DescribedObject >> UsingDescriptor >> !NestingOption)
;;;


NestingOption = WITH >> NESTING
  | WITHOUT >> NESTING
;;;


UsingDescriptor = (USING >> !SQL >> DESCRIPTOR >> DescriptorName)
;;;


DescribedObject = SQLStatementName
  | CURSOR >> ExtendedCursorName >> STRUCTURE
;;;


InputUsingClause = UsingArguments
  | UsingInputDescriptor
;;;


UsingArguments = (USING >> (UsingArgument%Comma))
;;;


UsingArgument = GeneralValueSpecification
;;;


UsingInputDescriptor = UsingDescriptor
;;;


OutputUsingClause = IntoArguments
  | IntoDescriptor
;;;


IntoArguments = (INTO >> (IntoArgument%Comma))
;;;


IntoArgument = TargetSpecification
;;;


IntoDescriptor = (INTO >> !SQL >> DESCRIPTOR >> DescriptorName)
;;;


ExecuteStatement = (EXECUTE >> SQLStatementName >> !ResultUsingClause >> !ParameterUsingClause)
;;;


ResultUsingClause = OutputUsingClause
;;;


ParameterUsingClause = InputUsingClause
;;;


ExecuteImmediateStatement = EXECUTE >> IMMEDIATE >> SQLStatementVariable
;;;


DynamicDeclareCursor = (DECLARE >> CursorName >> !CursorSensitivity >> !CursorScrollability >> CURSOR >> !CursorHoldability >> !CursorReturnability >> FOR >> StatementName)
;;;


AllocateCursorStatement = ALLOCATE >> ExtendedCursorName >> CursorIntent
;;;


CursorIntent = StatementCursor
  | ResultSetCursor
;;;


StatementCursor = !(CursorSensitivity >> !CursorScrollability >> CURSOR >> !CursorHoldability >> !CursorReturnability >> FOR >> ExtendedStatementName)
;;;


ResultSetCursor = FOR >> PROCEDURE >> SpecificRoutineDesignator
;;;


DynamicOpenStatement = (OPEN >> DynamicCursorName >> !InputUsingClause)
;;;


DynamicFetchStatement = (FETCH >> !!(FetchOrientation >> FROM) >> DynamicCursorName >> OutputUsingClause)
;;;


DynamicSingleRowSelectStatement = QuerySpecification
;;;


DynamicCloseStatement = CLOSE >> DynamicCursorName
;;;


DynamicDeleteStatementPositioned = DELETE >> FROM >> TargetTable >> WHERE >> CURRENT >> OF >> DynamicCursorName
;;;


DynamicUpdateStatementPositioned = UPDATE >> TargetTable >> SET >> SetClauseList >> WHERE >> CURRENT >> OF >> DynamicCursorName
;;;


PreparableDynamicDeleteStatementPositioned = (DELETE >> !FROM >> TargetTable >> WHERE >> CURRENT >> OF >> !ScopeOption >> CursorName)
;;;


PreparableDynamicUpdateStatementPositioned = (UPDATE >> !TargetTable >> SET >> SetClauseList >> WHERE >> CURRENT >> OF >> !ScopeOption >> CursorName)
;;;


EmbeddedSQLHostProgram = EmbeddedSQLAdaProgram
  | EmbeddedSQLCProgram
  | EmbeddedSQLCOBOLProgram
  | EmbeddedSQLFortranProgram
  | EmbeddedSQLMUMPSProgram
  | EmbeddedSQLPascalProgram
  | EmbeddedSQLPLIProgram
;;;


EmbeddedSQLStatement = (SQLPrefix >> StatementOrDeclaration >> !SQLTerminator)
;;;


StatementOrDeclaration = DeclareCursor
  | DynamicDeclareCursor
  | TemporaryTableDeclaration
  | EmbeddedAuthorizationDeclaration
  | EmbeddedPathSpecification
  | EmbeddedTransformGroupSpecification
  | EmbeddedCollationSpecification
  | EmbeddedExceptionDeclaration
  | HandlerDeclaration
  | SQLProcedureStatement
;;;


SQLPrefix = EXEC >> SQL
  | Ampersand >> SQL >> LeftParen
;;;


SQLTerminator = ENDEXEC
  | Semicolon
  | RightParen
;;;


EmbeddedAuthorizationDeclaration = DECLARE >> EmbeddedAuthorizationClause
;;;


EmbeddedAuthorizationClause = SCHEMA >> SchemaName
  | (AUTHORIZATION >> EmbeddedAuthorizationIdentifier >> !(FOR >> STATIC >> ONLY
  | AND >> DYNAMIC))
  | (SCHEMA >> SchemaName >> AUTHORIZATION >> EmbeddedAuthorizationIdentifier >> !(FOR >> STATIC >> ONLY
  | AND >> DYNAMIC))
;;;


EmbeddedAuthorizationIdentifier = ModuleAuthorizationIdentifier
;;;


EmbeddedPathSpecification = PathSpecification
;;;


EmbeddedTransformGroupSpecification = TransformGroupSpecification
;;;


EmbeddedCollationSpecification = ModuleCollations
;;;


EmbeddedSQLDeclareSection = (EmbeddedSQLBeginDeclare >> !EmbeddedCharacterSetDeclaration >> *HostVariableDefinition >> EmbeddedSQLEndDeclare)
  | EmbeddedSQLMUMPSDeclare
;;;


EmbeddedCharacterSetDeclaration = SQL >> NAMES >> ARE >> CharacterSetSpecification
;;;


EmbeddedSQLBeginDeclare = (SQLPrefix >> BEGIN >> DECLARE >> SECTION >> !SQLTerminator)
;;;


EmbeddedSQLEndDeclare = (SQLPrefix >> END >> DECLARE >> SECTION >> !SQLTerminator)
;;;


EmbeddedSQLMUMPSDeclare = (SQLPrefix >> BEGIN >> DECLARE >> SECTION >> !EmbeddedCharacterSetDeclaration >> +HostVariableDefinition) >> END >> DECLARE >> SECTION >> SQLTerminator)
;;;


HostVariableDefinition = AdaVariableDefinition
  | CVariableDefinition
  | COBOLVariableDefinition
  | FortranVariableDefinition
  | MUMPSVariableDefinition
  | PascalVariableDefinition
  | PLIVariableDefinition
;;;


EmbeddedVariableName = Colon >> HostIdentifier
;;;


HostIdentifier = AdaHostIdentifier
  | CHostIdentifier
  | COBOLHostIdentifier
  | FortranHostIdentifier
  | MUMPSHostIdentifier
  | PascalHostIdentifier
  | PLIHostIdentifier
;;;


EmbeddedExceptionDeclaration = WHENEVER >> Condition >> ConditionAction
;;;


Condition = SQLCondition
;;;


SQLCondition = MajorCategory
  | (SQLSTATE >> (SQLSTATEClassValue >> !,SQLSTATESubclassValue))
  | CONSTRAINT >> ConstraintName
;;;


MajorCategory = SQLEXCEPTION
  | SQLWARNING
  | NOT >> FOUND
;;;


SQLSTATEClassValue = SQLSTATEChar >> SQLSTATEChar!!See >> the >> Syntax >> Rules.
;;;


SQLSTATESubclassValue = SQLSTATEChar >> SQLSTATEChar >> SQLSTATEChar!!See >> The >> Syntax >> Rules.
;;;


SQLSTATEChar = SimpleLatinUpperCaseLetter
  | Digit
;;;


ConditionAction = CONTINUE
  | GoTo
;;;


GoTo = (GOTO
  | GO >> TO >> GotoTarget)
;;;


GotoTarget = HostLabelIdentifier
  | UnsignedInteger
  | HostPLILabelVariable
;;;


HostLabelIdentifier = !!See >> the >> Syntax >> Rules.
;;;


HostPLILabelVariable = !!See >> The >> Syntax >> Rules.
;;;


EmbeddedSQLAdaProgram = !!See >> The >> Syntax >> Rules.
;;;


AdaVariableDefinition = ((AdaHostIdentifier%Comma) >> Colon >> AdaTypeSpecification >> !AdaInitialValue)
;;;


AdaInitialValue = (AdaAssignmentOperator >> +CharacterRepresentation)
;;;


AdaAssignmentOperator = Colon >> EqualsOperator
;;;


AdaHostIdentifier = !!See >> The >> Syntax >> Rules.
;;;


AdaTypeSpecification = AdaQualifiedTypeSpecification
  | AdaUnqualifiedTypeSpecification
  | AdaDerivedTypeSpecification
;;;


AdaQualifiedTypeSpecification = Interfaces.(SQL >> Period >> CHAR >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> LeftParen >> 1 >> DoublePeriod >> Length >> RightParen)
  | InterfacesSQL >> Period >> SMALLINT
  | Interfaces.SQL >> Period >> INT
  | InterfacesSQL >> Period >> BIGINT
  | Interfaces.SQL >> Period >> REAL
  | InterfacesSQL >> Period >> DOUBLE_PRECISION
  | Interfaces.SQL >> Period >> BOOLEAN
  | InterfacesSQL >> Period >> SQLSTATE_TYPE
  | Interfaces.SQL >> Period >> INDICATOR_TYPE
;;;


AdaUnqualifiedTypeSpecification = CHAR >> LeftParen >> 1 >> DoublePeriod >> Length >> RightParen
  | SMALLINT
  | INT
  | BIGINT
  | REAL
  | DOUBLE_PRECISION
  | BOOLEAN
  | SQLSTATE_TYPE
  | INDICATOR_TYPE
;;;


AdaDerivedTypeSpecification = AdaCLOBVariable
  | AdaCLOBLocatorVariable
  | AdaBLOBVariable
  | AdaBLOBLocatorVariable
  | AdaUserDefinedTypeVariable
  | AdaUserDefinedTypeLocatorVariable
  | AdaREFVariable
  | AdaArrayLocatorVariable
  | AdaMultisetLocatorVariable
;;;


AdaCLOBVariable = (SQL >> TYPE >> IS >> CLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
;;;


AdaCLOBLocatorVariable = SQL >> TYPE >> IS >> CLOB >> AS >> LOCATOR
;;;


AdaBLOBVariable = SQL >> TYPE >> IS >> BLOB >> LeftParen >> LargeObjectLength >> RightParen
;;;


AdaBLOBLocatorVariable = SQL >> TYPE >> IS >> BLOB >> AS >> LOCATOR
;;;


AdaUserDefinedTypeVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> PredefinedType
;;;


AdaUserDefinedTypeLocatorVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> LOCATOR
;;;


AdaREFVariable = SQL >> TYPE >> IS >> ReferenceType
;;;


AdaArrayLocatorVariable = SQL >> TYPE >> IS >> ArrayType >> AS >> LOCATOR
;;;


AdaMultisetLocatorVariable = SQL >> TYPE >> IS >> MultisetType >> AS >> LOCATOR
;;;


EmbeddedSQLCProgram = !!See >> The >> Syntax >> Rules.
;;;


CVariableDefinition = !(CStorageClass >> !CClassModifier >> CVariableSpecification >> Semicolon)
;;;


CVariableSpecification = CNumericVariable
  | CCharacterVariable
  | CDerivedVariable
;;;


CStorageClass = Auto
  | Extern
  | Static
;;;


CClassModifier = const
  | volatile
;;;


CNumericVariable = (Long >> Long
  | Long
  | Short
  | Float
  | Double >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CCharacterVariable = (CCharacterType >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> CHostIdentifier >> CArraySpecification >> !CInitialValue >> *((Comma >> CHostIdentifier >> CArraySpecification >> !CInitialValue)))
;;;


CCharacterType = Char
  | Unsigned >> Char
  | Unsigned >> Short
;;;


CArraySpecification = LeftBracket >> Length >> RightBracket
;;;


CHostIdentifier = !!See >> the >> Syntax >> Rules.
;;;


CDerivedVariable = CVARCHARVariable
  | CNCHARVariable
  | CNCHARVARYINGVariable
  | CCLOBVariable
  | CNCLOBVariable
  | CBLOBVariable
  | CUserDefinedTypeVariable
  | CCLOBLocatorVariable
  | CBLOBLocatorVariable
  | CArrayLocatorVariable
  | CMultisetLocatorVariable
  | CUserDefinedTypeLocatorVariable
  | CREFVariable
;;;


CVARCHARVariable = (VARCHAR >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> CHostIdentifier >> CArraySpecification >> !CInitialValue >> *((Comma >> CHostIdentifier >> CArraySpecification >> !CInitialValue)))
;;;


CNCHARVariable = (NCHAR >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> CHostIdentifier >> CArraySpecification >> !CInitialValue >> *((Comma >> CHostIdentifier >> CArraySpecification >> !CInitialValue)))
;;;


CNCHARVARYINGVariable = (NCHAR >> VARYING >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> CHostIdentifier >> CArraySpecification >> !CInitialValue >> *((Comma >> CHostIdentifier >> CArraySpecification >> !CInitialValue)))
;;;


CCLOBVariable = (SQL >> TYPE >> IS >> CLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CNCLOBVariable = (SQL >> TYPE >> IS >> NCLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CUserDefinedTypeVariable = (SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> PredefinedType >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CBLOBVariable = (SQL >> TYPE >> IS >> BLOB >> LeftParen >> LargeObjectLength >> RightParen >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CCLOBLocatorVariable = (SQL >> TYPE >> IS >> CLOB >> AS >> LOCATOR >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CBLOBLocatorVariable = (SQL >> TYPE >> IS >> BLOB >> AS >> LOCATOR >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CArrayLocatorVariable = (SQL >> TYPE >> IS >> ArrayType >> AS >> LOCATOR >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CMultisetLocatorVariable = (SQL >> TYPE >> IS >> MultisetType >> AS >> LOCATOR >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CUserDefinedTypeLocatorVariable = (SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> LOCATOR >> CHostIdentifier >> !CInitialValue >> *((Comma >> CHostIdentifier >> !CInitialValue)))
;;;


CREFVariable = SQL >> TYPE >> IS >> ReferenceType
;;;


CInitialValue = (EqualsOperator >> +CharacterRepresentation)
;;;


EmbeddedSQLCOBOLProgram = !!See >> the >> Syntax >> Rules.
;;;


COBOLVariableDefinition = (01
  | 77 >> COBOLHostIdentifier >> COBOLTypeSpecification >> *CharacterRepresentation >> Period)
;;;


COBOLHostIdentifier = !!See >> The >> Syntax >> Rules.
;;;


COBOLTypeSpecification = COBOLCharacterType
  | COBOLNationalCharacterType
  | COBOLNumericType
  | COBOLIntegerType
  | COBOLDerivedTypeSpecification
;;;


COBOLDerivedTypeSpecification = COBOLCLOBVariable
  | COBOLNCLOBVariable
  | COBOLBLOBVariable
  | COBOLUserDefinedTypeVariable
  | COBOLCLOBLocatorVariable
  | COBOLBLOBLocatorVariable
  | COBOLArrayLocatorVariable
  | COBOLMultisetLocatorVariable
  | COBOLUserDefinedTypeLocatorVariable
  | COBOLREFVariable
;;;


COBOLCharacterType = !((CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> PIC
  | PICTURE >> !IS >> +(X >> !LeftParen >> Length >> RightParen))
;;;


COBOLNationalCharacterType = !((CHARACTER >> SET >> !IS >> CharacterSetSpecification) >> PIC
  | PICTURE >> !IS >> +(N >> !LeftParen >> Length >> RightParen))
;;;


COBOLCLOBVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> CLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
;;;


COBOLNCLOBVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> NCLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
;;;


COBOLBLOBVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> BLOB >> LeftParen >> LargeObjectLength >> RightParen)
;;;


COBOLUserDefinedTypeVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> PredefinedType)
;;;


COBOLCLOBLocatorVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> CLOB >> AS >> LOCATOR)
;;;


COBOLBLOBLocatorVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> BLOB >> AS >> LOCATOR)
;;;


COBOLArrayLocatorVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> ArrayType >> AS >> LOCATOR)
;;;


COBOLMultisetLocatorVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> MultisetType >> AS >> LOCATOR)
;;;


COBOLUserDefinedTypeLocatorVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> LOCATOR)
;;;


COBOLREFVariable = !((USAGE >> !IS) >> SQL >> TYPE >> IS >> ReferenceType)
;;;


COBOLNumericType = (PIC
  | PICTURE >> !IS >> S >> COBOLNinesSpecification >> !(USAGE >> !IS) >> DISPLAY >> SIGN >> LEADING >> SEPARATE)
;;;


COBOLNinesSpecification = (COBOLNines >> !(V >> !COBOLNines))
  | V >> COBOLNines
;;;


COBOLIntegerType = COBOLBinaryInteger
;;;


COBOLBinaryInteger = (PIC
  | PICTURE >> !IS >> S >> COBOLNines >> !(USAGE >> !IS) >> BINARY)
;;;


COBOLNines = +((9 >> !LeftParen >> Length >> RightParen))
;;;


EmbeddedSQLFortranProgram = !!See >> the >> Syntax >> Rules.
;;;


FortranVariableDefinition = (FortranTypeSpecification >> (FortranHostIdentifier%Comma))
;;;


FortranHostIdentifier = !!See >> the >> Syntax >> Rules.
;;;


FortranTypeSpecification = (CHARACTER >> !Asterisk >> Length >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
  | CHARACTER >> KIND=(n >> !Asterisk >> Length >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
  | INTEGER
  | REAL
  | DOUBLE >> PRECISION
  | LOGICAL
  | FortranDerivedTypeSpecification
;;;


FortranDerivedTypeSpecification = FortranCLOBVariable
  | FortranBLOBVariable
  | FortranUserDefinedTypeVariable
  | FortranCLOBLocatorVariable
  | FortranBLOBLocatorVariable
  | FortranUserDefinedTypeLocatorVariable
  | FortranArrayLocatorVariable
  | FortranMultisetLocatorVariable
  | FortranREFVariable
;;;


FortranCLOBVariable = (SQL >> TYPE >> IS >> CLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
;;;


FortranBLOBVariable = SQL >> TYPE >> IS >> BLOB >> LeftParen >> LargeObjectLength >> RightParen
;;;


FortranUserDefinedTypeVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> PredefinedType
;;;


FortranCLOBLocatorVariable = SQL >> TYPE >> IS >> CLOB >> AS >> LOCATOR
;;;


FortranBLOBLocatorVariable = SQL >> TYPE >> IS >> BLOB >> AS >> LOCATOR
;;;


FortranUserDefinedTypeLocatorVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> LOCATOR
;;;


FortranArrayLocatorVariable = SQL >> TYPE >> IS >> ArrayType >> AS >> LOCATOR
;;;


FortranMultisetLocatorVariable = SQL >> TYPE >> IS >> MultisetType >> AS >> LOCATOR
;;;


FortranREFVariable = SQL >> TYPE >> IS >> ReferenceType
;;;


EmbeddedSQLMUMPSProgram = !!See >> the >> Syntax >> Rules.
;;;


MUMPSVariableDefinition = MUMPSNumericVariable >> Semicolon
  | MUMPSCharacterVariable >> Semicolon
  | MUMPSDerivedTypeSpecification >> Semicolon
;;;


MUMPSCharacterVariable = (VARCHAR >> MUMPSHostIdentifier >> MUMPSLengthSpecification >> *(Comma >> MUMPSHostIdentifier >> MUMPSLengthSpecification))
;;;


MUMPSHostIdentifier = !!See >> The >> Syntax >> Rules.
;;;


MUMPSLengthSpecification = LeftParen >> Length >> RightParen
;;;


MUMPSNumericVariable = (MUMPSTypeSpecification >> (MUMPSHostIdentifier%Comma))
;;;


MUMPSTypeSpecification = INT
  | (DEC >> !(LeftParen >> Precision >> !Comma >> Scale >> RightParen))
  | REAL
;;;


MUMPSDerivedTypeSpecification = MUMPSCLOBVariable
  | MUMPSBLOBVariable
  | MUMPSUserDefinedTypeVariable
  | MUMPSCLOBLocatorVariable
  | MUMPSBLOBLocatorVariable
  | MUMPSUserDefinedTypeLocatorVariable
  | MUMPSArrayLocatorVariable
  | MUMPSMultisetLocatorVariable
  | MUMPSREFVariable
;;;


MUMPSCLOBVariable = (SQL >> TYPE >> IS >> CLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
;;;


MUMPSBLOBVariable = SQL >> TYPE >> IS >> BLOB >> LeftParen >> LargeObjectLength >> RightParen
;;;


MUMPSUserDefinedTypeVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> PredefinedType
;;;


MUMPSCLOBLocatorVariable = SQL >> TYPE >> IS >> CLOB >> AS >> LOCATOR
;;;


MUMPSBLOBLocatorVariable = SQL >> TYPE >> IS >> BLOB >> AS >> LOCATOR
;;;


MUMPSUserDefinedTypeLocatorVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> LOCATOR
;;;


MUMPSArrayLocatorVariable = SQL >> TYPE >> IS >> ArrayType >> AS >> LOCATOR
;;;


MUMPSMultisetLocatorVariable = SQL >> TYPE >> IS >> MultisetType >> AS >> LOCATOR
;;;


MUMPSREFVariable = SQL >> TYPE >> IS >> ReferenceType
;;;


EmbeddedSQLPascalProgram = !!See >> The >> Syntax >> Rules.
;;;


PascalVariableDefinition = ((PascalHostIdentifier%Comma) >> Colon >> PascalTypeSpecification >> Semicolon)
;;;


PascalHostIdentifier = !!See >> The >> Syntax >> Rules.
;;;


PascalTypeSpecification = (PACKED >> ARRAY >> LeftBracket >> 1 >> DoublePeriod >> Length >> RightBracket >> OF >> CHAR >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
  | INTEGER
  | REAL
  | (CHAR >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
  | BOOLEAN
  | PascalDerivedTypeSpecification
;;;


PascalDerivedTypeSpecification = PascalCLOBVariable
  | PascalBLOBVariable
  | PascalUserDefinedTypeVariable
  | PascalCLOBLocatorVariable
  | PascalBLOBLocatorVariable
  | PascalUserDefinedTypeLocatorVariable
  | PascalArrayLocatorVariable
  | PascalMultisetLocatorVariable
  | PascalREFVariable
;;;


PascalCLOBVariable = (SQL >> TYPE >> IS >> CLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
;;;


PascalBLOBVariable = SQL >> TYPE >> IS >> BLOB >> LeftParen >> LargeObjectLength >> RightParen
;;;


PascalCLOBLocatorVariable = SQL >> TYPE >> IS >> CLOB >> AS >> LOCATOR
;;;


PascalUserDefinedTypeVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> PredefinedType
;;;


PascalBLOBLocatorVariable = SQL >> TYPE >> IS >> BLOB >> AS >> LOCATOR
;;;


PascalUserDefinedTypeLocatorVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> LOCATOR
;;;


PascalArrayLocatorVariable = SQL >> TYPE >> IS >> ArrayType >> AS >> LOCATOR
;;;


PascalMultisetLocatorVariable = SQL >> TYPE >> IS >> MultisetType >> AS >> LOCATOR
;;;


PascalREFVariable = SQL >> TYPE >> IS >> ReferenceType
;;;


EmbeddedSQLPLIProgram = !!See >> The >> Syntax >> Rules.
;;;


PLIVariableDefinition = (DCL
  | DECLARE >> PLIHostIdentifier
  | (LeftParen >> (PLIHostIdentifier%Comma) >> RightParen) >> PLITypeSpecification >> *CharacterRepresentation >> Semicolon)
;;;


PLIHostIdentifier = !!See >> The >> Syntax >> Rules.
;;;


PLITypeSpecification = (CHAR
  | CHARACTER >> !VARYING >> LeftParen >> Length >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
  | (PLITypeFixedDecimal >> LeftParen >> Precision >> !Comma >> Scale >> RightParen)
  | (PLITypeFixedBinary >> !LeftParen >> Precision >> RightParen)
  | PLITypeFloatBinary >> LeftParen >> Precision >> RightParen
  | PLIDerivedTypeSpecification
;;;


PLIDerivedTypeSpecification = PLICLOBVariable
  | PLIBLOBVariable
  | PLIUserDefinedTypeVariable
  | PLICLOBLocatorVariable
  | PLIBLOBLocatorVariable
  | PLIUserDefinedTypeLocatorVariable
  | PLIArrayLocatorVariable
  | PLIMultisetLocatorVariable
  | PLIREFVariable
;;;


PLICLOBVariable = (SQL >> TYPE >> IS >> CLOB >> LeftParen >> LargeObjectLength >> RightParen >> !(CHARACTER >> SET >> !IS >> CharacterSetSpecification))
;;;


PLIBLOBVariable = SQL >> TYPE >> IS >> BLOB >> LeftParen >> LargeObjectLength >> RightParen
;;;


PLIUserDefinedTypeVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> PredefinedType
;;;


PLICLOBLocatorVariable = SQL >> TYPE >> IS >> CLOB >> AS >> LOCATOR
;;;


PLIBLOBLocatorVariable = SQL >> TYPE >> IS >> BLOB >> AS >> LOCATOR
;;;


PLIUserDefinedTypeLocatorVariable = SQL >> TYPE >> IS >> PathResolvedUserDefinedTypeName >> AS >> LOCATOR
;;;


PLIArrayLocatorVariable = SQL >> TYPE >> IS >> ArrayType >> AS >> LOCATOR
;;;


PLIMultisetLocatorVariable = SQL >> TYPE >> IS >> MultisetType >> AS >> LOCATOR
;;;


PLIREFVariable = SQL >> TYPE >> IS >> ReferenceType
;;;


PLITypeFixedDecimal = (DEC
  | DECIMAL >> FIXED)
  | (FIXED >> DEC
  | DECIMAL)
;;;


PLITypeFixedBinary = (BIN
  | BINARY >> FIXED)
  | (FIXED >> BIN
  | BINARY)
;;;


PLITypeFloatBinary = (BIN
  | BINARY >> FLOAT)
  | (FLOAT >> BIN
  | BINARY)
;;;


DirectSQLStatement = DirectlyExecutableStatement >> Semicolon
;;;


DirectlyExecutableStatement = DirectSQLDataStatement
  | SQLSchemaStatement
  | SQLTransactionStatement
  | SQLConnectionStatement
  | SQLSessionStatement
  | DirectImplementationDefinedStatement
;;;


DirectSQLDataStatement = DeleteStatementSearched
  | DirectSelectStatementMultipleRows
  | InsertStatement
  | UpdateStatementSearched
  | MergeStatement
  | TemporaryTableDeclaration
;;;


DirectImplementationDefinedStatement = !!See >> the >> Syntax >> Rules
;;;


DirectSelectStatementMultipleRows = CursorSpecification
;;;


GetDiagnosticsStatement = GET >> DIAGNOSTICS >> SQLDiagnosticsInformation
;;;


SQLDiagnosticsInformation = StatementInformation
  | ConditionInformation
;;;


StatementInformation = ((StatementInformationItem%Comma))
;;;


StatementInformationItem = SimpleTargetSpecification >> EqualsOperator >> StatementInformationItemName
;;;


StatementInformationItemName = NUMBER
  | MORE
  | COMMAND_FUNCTION
  | COMMAND_FUNCTION_CODE
  | DYNAMIC_FUNCTION
  | DYNAMIC_FUNCTION_CODE
  | ROW_COUNT
  | TRANSACTIONS_COMMITTED
  | TRANSACTIONS_ROLLED_BACK
  | TRANSACTION_ACTIVE
;;;


ConditionInformation = (EXCEPTION
  | CONDITION >> ConditionNumber >> (ConditionInformationItem%Comma))
;;;


ConditionInformationItem = SimpleTargetSpecification >> EqualsOperator >> ConditionInformationItemName
;;;


ConditionInformationItemName = CATALOG_NAME
  | CLASS_ORIGIN
  | COLUMN_NAME
  | CONDITION_NUMBER
  | CONNECTION_NAME
  | CONSTRAINT_CATALOG
  | CONSTRAINT_NAME
  | CONSTRAINT_SCHEMA
  | CURSOR_NAME
  | MESSAGE_LENGTH
  | MESSAGE_OCTET_LENGTH
  | MESSAGE_TEXT
  | PARAMETER_MODE
  | PARAMETER_NAME
  | PARAMETER_ORDINAL_POSITION
  | RETURNED_SQLSTATE
  | ROUTINE_CATALOG
  | ROUTINE_NAME
  | ROUTINE_SCHEMA
  | SCHEMA_NAME
  | SERVER_NAME
  | SPECIFIC_NAME
  | SUBCLASS_ORIGIN
  | TABLE_NAME
  | TRIGGER_CATALOG
  | TRIGGER_NAME
  | TRIGGER_SCHEMA
;;;


ConditionNumber = SimpleValueSpecification